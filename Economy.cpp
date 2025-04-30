#include "stronghold.h"
#include <iostream>

Economy::Economy() {
    treasury = 1000;
    taxRate = 0.1f; // 10%
    inflation = 5;
    atWar = false;
}

void Economy::collectTaxes(int populationSize) {
    int income = populationSize * 10;
    int taxCollected = static_cast<int>(income * taxRate);
    treasury += taxCollected;
    std::cout << "Collected " << taxCollected << " gold in taxes.\n";
}

void Economy::spendOnServices(int amount) {
    if (amount > treasury) {
        std::cout << "Not enough gold to spend.\n";
        return;
    }
    treasury -= amount;
    std::cout << "Spent " << amount << " gold on public services.\n";
}

void Economy::declareWar() {
    atWar = true;
    inflation += 5;
    std::cout << "War declared. Inflation increased.\n";
}

void Economy::endWar() {
    atWar = false;
    inflation -= 3;
    if (inflation < 0) inflation = 0;
    std::cout << "War ended. Inflation reduced.\n";
}

void Economy::applyInflation() {
    int loss = (treasury * inflation) / 100;
    treasury -= loss;
    std::cout << "Inflation reduced treasury by " << loss << " gold.\n";
}

int Economy::getTreasury() const {
    return treasury;
}

void Economy::displayStatus() const {
    std::cout << "Economy Status:\n";
    std::cout << " Treasury: " << treasury << " gold\n";
    std::cout << " Tax Rate: " << taxRate * 100 << "%\n";
    std::cout << " Inflation: " << inflation << "%\n";
    std::cout << " At War: " << (atWar ? "Yes" : "No") << "\n";
}

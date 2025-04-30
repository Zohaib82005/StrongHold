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
     cout << "Collected " << taxCollected << " gold in taxes.\n";
}

void Economy::spendOnServices(int amount) {
    if (amount > treasury) {
         cout << "Not enough gold to spend.\n";
        return;
    }
    treasury -= amount;
     cout << "Spent " << amount << " gold on public services.\n";
}

void Economy::declareWar() {
    atWar = true;
    inflation += 5;
     cout << "War declared. Inflation increased.\n";
}

void Economy::endWar() {
    atWar = false;
    inflation -= 3;
    if (inflation < 0) inflation = 0;
     cout << "War ended. Inflation reduced.\n";
}

void Economy::applyInflation() {
    int loss = (treasury * inflation) / 100;
    treasury -= loss;
     cout << "Inflation reduced treasury by " << loss << " gold.\n";
}

int Economy::getTreasury() const {
    return treasury;
}

void Economy::displayStatus() const {
     cout << "Economy Status:\n";
     cout << " Treasury: " << treasury << " gold\n";
     cout << " Tax Rate: " << taxRate * 100 << "%\n";
     cout << " Inflation: " << inflation << "%\n";
     cout << " At War: " << (atWar ? "Yes" : "No") << "\n";
}
void Economy::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    outFile << treasury << " " << taxRate << " " << inflation << " "
        << (atWar ? 1 : 0) <<  endl;

    outFile.close(); 
     cout << "Economy data saved to file: " << filename <<  endl;
}

void Economy::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

    int warFlag; 
    inFile >> treasury >> taxRate >> inflation >> warFlag;

    atWar = (warFlag == 1);

    inFile.close(); 
     cout << "Economy data loaded from file: " << filename <<  endl;
}
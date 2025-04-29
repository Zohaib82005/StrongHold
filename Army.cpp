#include "Army.h"
#include <iostream>
#include <stdexcept>

Army::Army() {
    soldiers = 50;
    morale = 70;
    corruption = 10;
    foodSupply = 100;
    goldSupply = 500;
}

void Army::recruit(int availablePop) {
    if (availablePop < 10)
        throw std::runtime_error("Not enough people to recruit.");

    int newRecruits = availablePop / 10;
    soldiers += newRecruits;
    morale += 2;
    std::cout << "Recruited " << newRecruits << " soldiers.\n";
}

void Army::train() {
    if (goldSupply < 50) {
        std::cout << "Insufficient gold to train army.\n";
        return;
    }
    goldSupply -= 50;
    morale += 5;
    std::cout << "Army trained. Morale increased.\n";
}

void Army::feedAndPay() {
    if (foodSupply < soldiers || goldSupply < (soldiers * 2)) {
        morale -= 10;
        corruption += 5;
        std::cout << "Underfed or unpaid army. Morale dropped.\n";
    }
    else {
        foodSupply -= soldiers;
        goldSupply -= (soldiers * 2);
        morale += 3;
        std::cout << "Army fed and paid.\n";
    }
}

int Army::getStrength() const {
    return (soldiers * morale) / 100 - corruption;
}

void Army::displayStatus() const {
    std::cout << "Army Status:\n";
    std::cout << " Soldiers: " << soldiers << "\n";
    std::cout << " Morale: " << morale << "\n";
    std::cout << " Corruption: " << corruption << "\n";
    std::cout << " Food Supply: " << foodSupply << "\n";
    std::cout << " Gold Supply: " << goldSupply << "\n";
    std::cout << " Strength Score: " << getStrength() << "\n";
}

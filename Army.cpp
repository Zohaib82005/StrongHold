#include "stronghold.h"
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
        throw  runtime_error("Not enough people to recruit.");

    int newRecruits = availablePop / 10;
    soldiers += newRecruits;
    morale += 2;
     cout << "Recruited " << newRecruits << " soldiers.\n";
}

void Army::train() {
    if (goldSupply < 50) {
         cout << "Insufficient gold to train army.\n";
        return;
    }
    goldSupply -= 50;
    morale += 5;
     cout << "Army trained. Morale increased.\n";
}

void Army::feedAndPay() {
    if (foodSupply < soldiers || goldSupply < (soldiers * 2)) {
        morale -= 10;
        corruption += 5;
         cout << "Underfed or unpaid army. Morale dropped.\n";
    }
    else {
        foodSupply -= soldiers;
        goldSupply -= (soldiers * 2);
        morale += 3;
         cout << "Army fed and paid.\n";
    }
}

int Army::getStrength() const {
    return (soldiers * morale) / 100 - corruption;
}

void Army::displayStatus() const {
     cout << "Army Status:\n";
     cout << " Soldiers: " << soldiers << "\n";
     cout << " Morale: " << morale << "\n";
     cout << " Corruption: " << corruption << "\n";
     cout << " Food Supply: " << foodSupply << "\n";
     cout << " Gold Supply: " << goldSupply << "\n";
     cout << " Strength Score: " << getStrength() << "\n";
}
void Army::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }
    outFile << soldiers << " " << morale << " " << corruption << " "
        << foodSupply << " " << goldSupply <<  endl;

    outFile.close(); 
     cout << "Army data saved to file: " << filename <<  endl;
}
void Army::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

    inFile >> soldiers >> morale >> corruption >> foodSupply >> goldSupply;

    inFile.close();
     cout << "Army data loaded from file: " << filename <<  endl;
}

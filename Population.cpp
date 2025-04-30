#include "stronghold.h"
#include <iostream>

Population::Population() {
    peasants = 100;
    merchants = 25;
    nobles = 10;
    ill = 0;
    revolting = 0;
}

void Population::simulateGrowth(int food, int shelter, int jobs) {
    int totalPop = getTotalPopulation();
    if (food < totalPop || shelter < totalPop || jobs < (peasants + merchants)) {
         cout << "Growth stalled due to poor conditions.\n";
        return;
    }

    peasants += 5;
    merchants += 2;
     cout << "Population grew: +5 peasants, +2 merchants\n";
}

void Population::applyIllness(int severity) {
    int affected = severity * 2; // simple model
    ill += affected;
    peasants -= affected / 2;
    merchants -= affected / 3;
    nobles -= affected / 6;
     cout << "Illness hit! " << affected << " fell ill.\n";
}

void Population::checkForRevolt() {
    if (peasants < 50) {
        revolting = 1;
         cout << "Peasant revolt triggered!\n";
    }
}

int Population::getTotalPopulation() const {
    return peasants + merchants + nobles;
}

int Population::getWorkingClass() const {
    return peasants + merchants;
}

void Population::displayStatus() const {
     cout << "Population Report:\n";
     cout << " Peasants: " << peasants << "\n";
     cout << " Merchants: " << merchants << "\n";
     cout << " Nobles: " << nobles << "\n";
     cout << " Ill: " << ill << "\n";
     cout << " Revolting: " << (revolting ? "Yes" : "No") << "\n";
}

void Population::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    
    outFile << peasants << " " << merchants << " " << nobles << " "
        << ill << " " << revolting <<  endl;

    outFile.close(); 
     cout << "Population data saved to file: " << filename <<  endl;
}

void Population::loadFromFile(const  string& filename) {
     ifstream inFile(filename);
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }


    inFile >> peasants >> merchants >> nobles >> ill >> revolting;

    inFile.close(); 
     cout << "Population data loaded from file: " << filename <<  endl;
}
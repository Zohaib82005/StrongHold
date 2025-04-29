#include "Population.h"
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
        std::cout << "Growth stalled due to poor conditions.\n";
        return;
    }

    peasants += 5;
    merchants += 2;
    std::cout << "Population grew: +5 peasants, +2 merchants\n";
}

void Population::applyIllness(int severity) {
    int affected = severity * 2; // simple model
    ill += affected;
    peasants -= affected / 2;
    merchants -= affected / 3;
    nobles -= affected / 6;
    std::cout << "Illness hit! " << affected << " fell ill.\n";
}

void Population::checkForRevolt() {
    if (peasants < 50) {
        revolting = 1;
        std::cout << "Peasant revolt triggered!\n";
    }
}

int Population::getTotalPopulation() const {
    return peasants + merchants + nobles;
}

int Population::getWorkingClass() const {
    return peasants + merchants;
}

void Population::displayStatus() const {
    std::cout << "Population Report:\n";
    std::cout << " Peasants: " << peasants << "\n";
    std::cout << " Merchants: " << merchants << "\n";
    std::cout << " Nobles: " << nobles << "\n";
    std::cout << " Ill: " << ill << "\n";
    std::cout << " Revolting: " << (revolting ? "Yes" : "No") << "\n";
}

#include "EventManager.h"
#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>   // for seeding random

EventManager::EventManager() {
    std::srand(static_cast<unsigned>(time(0))); // seed random generator
}

void EventManager::triggerRandomEvent() {
    int eventID = std::rand() % 5;

    switch (eventID) {
    case 0:
        std::cout << "[EVENT] Famine has struck! Food reserves are reduced.\n";
        break;
    case 1:
        std::cout << "[EVENT] A deadly disease is spreading! Population is affected.\n";
        break;
    case 2:
        std::cout << "[EVENT] War erupts at the border! Army resources are drained.\n";
        break;
    case 3:
        std::cout << "[EVENT] A massive storm has damaged resource stockpiles!\n";
        break;
    case 4:
        std::cout << "[EVENT] A betrayal in the court causes political instability!\n";
        break;
    default:
        std::cout << "[EVENT] Nothing unusual occurred this season.\n";
        break;
    }
}

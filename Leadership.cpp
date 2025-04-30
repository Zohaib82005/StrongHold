#include "stronghold.h"
#include <iostream>

Leadership::Leadership() {
    currentLeader = "King Aldric";
    policy = "Balanced";
    popularity = 75;
    inPower = true;
}

void Leadership::holdElection(const std::string& newLeader) {
    if (popularity < 50) {
        std::cout << "Election failed. People did not support it.\n";
        return;
    }

    currentLeader = newLeader;
    policy = "Reformist";
    popularity = 65;
    std::cout << "Election successful. New leader: " << currentLeader << "\n";
}

void Leadership::initiateCoup() {
    if (popularity < 30) {
        inPower = false;
        std::cout << "Coup succeeded. Leadership has fallen.\n";
    }
    else {
        popularity -= 15;
        std::cout << "Coup attempt failed. Popularity reduced.\n";
    }
}

void Leadership::changePolicy(const std::string& newPolicy) {
    policy = newPolicy;
    popularity -= 5;
    std::cout << "Policy changed to: " << policy << "\n";
}

void Leadership::assessStability() {
    if (popularity < 20) {
        std::cout << "Unstable kingdom! Risk of revolt or coup.\n";
    }
    else if (popularity < 50) {
        std::cout << "Moderate unrest in the population.\n";
    }
    else {
        std::cout << "The kingdom is stable.\n";
    }
}

void Leadership::displayStatus() const {
    std::cout << "Leadership Status:\n";
    std::cout << " Leader: " << currentLeader << "\n";
    std::cout << " Policy: " << policy << "\n";
    std::cout << " Popularity: " << popularity << "\n";
    std::cout << " In Power: " << (inPower ? "Yes" : "No") << "\n";
}

std::string Leadership::getPolicy() const {
    return policy;
}

bool Leadership::isInPower() const {
    return inPower;
}

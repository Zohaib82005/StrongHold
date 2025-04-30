#include "stronghold.h"
#include <iostream>

Leadership::Leadership() {
    currentLeader = "King Aldric";
    policy = "Balanced";
    popularity = 75;
    inPower = true;
}

void Leadership::holdElection(const  string& newLeader) {
    if (popularity < 50) {
         cout << "Election failed. People did not support it.\n";
        return;
    }

    currentLeader = newLeader;
    policy = "Reformist";
    popularity = 65;
     cout << "Election successful. New leader: " << currentLeader << "\n";
}

void Leadership::initiateCoup() {
    if (popularity < 30) {
        inPower = false;
         cout << "Coup succeeded. Leadership has fallen.\n";
    }
    else {
        popularity -= 15;
         cout << "Coup attempt failed. Popularity reduced.\n";
    }
}

void Leadership::changePolicy(const  string& newPolicy) {
    policy = newPolicy;
    popularity -= 5;
     cout << "Policy changed to: " << policy << "\n";
}

void Leadership::assessStability() {
    if (popularity < 20) {
         cout << "Unstable kingdom! Risk of revolt or coup.\n";
    }
    else if (popularity < 50) {
         cout << "Moderate unrest in the population.\n";
    }
    else {
         cout << "The kingdom is stable.\n";
    }
}

void Leadership::displayStatus() const {
     cout << "Leadership Status:\n";
     cout << " Leader: " << currentLeader << "\n";
     cout << " Policy: " << policy << "\n";
     cout << " Popularity: " << popularity << "\n";
     cout << " In Power: " << (inPower ? "Yes" : "No") << "\n";
}

 string Leadership::getPolicy() const {
    return policy;
}

bool Leadership::isInPower() const {
    return inPower;
}
void Leadership::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

   
     getline(inFile, currentLeader); 
     getline(inFile, policy);        
    int powerFlag;                      
    inFile >> popularity >> powerFlag;

    
    inPower = (powerFlag == 1);

    inFile.close(); 
     cout << "Leadership data loaded from file: " << filename <<  endl;
}

void Leadership::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    outFile << currentLeader << "\n" << policy << "\n" << popularity << " "
        << (inPower ? 1 : 0) <<  endl;

    outFile.close(); 
     cout << "Leadership data saved to file: " << filename <<  endl;
}

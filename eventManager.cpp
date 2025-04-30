#include "stronghold.h"
#include <iostream>
#include <fstream> // For file handling
#include <cstdlib> // For rand()
#include <ctime>   // For time()

EventManager::EventManager() {
    lastEvent = "No events triggered yet.";
    eventCount = 0;
}

void EventManager::triggerRandomEvent() {
    const  string events[] = {
        "A bountiful harvest increases food supply!",
        "A sudden drought reduces water availability.",
        "Bandits raid nearby villages.",
        "A merchant caravan brings wealth to the kingdom.",
        "An outbreak of illness spreads among the population."
    };

    int index = rand() % 5; 
    lastEvent = events[index];
    eventCount++;
     cout << "[EVENT] " << lastEvent <<  endl;
}


void EventManager::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    
    outFile << lastEvent << "\n" << eventCount <<  endl;

    outFile.close(); 
     cout << "EventManager data saved to file: " << filename <<  endl;
}

void EventManager::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

    
    getline(inFile, lastEvent);
    inFile >> eventCount;           

    inFile.close(); 
     cout << "EventManager data loaded from file: " << filename <<  endl;
}


 string EventManager::getLastEvent() const {
    return lastEvent;
}

int EventManager::getEventCount() const {
    return eventCount;
}
// Map.cpp
#include "stronghold.h"
#include <iostream>

Map::Map() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            grid[y][x] = '.';
        }
    }
    grid[2][2] = 'K'; 
}

void Map::display() const {
     cout << "\n=== KINGDOM MAP ===\n";
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
             cout << grid[y][x] << " ";
        }
         cout << "\n";
    }
     cout << "=================\n";
}

bool Map::placeBuilding(char buildingType, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && grid[y][x] == '.') {
        grid[y][x] = buildingType;
        return true;
    }
     cout << "[Map] Cannot build there.\n";
    return false;
}

void Map::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            outFile << grid[i][j];
        }
        outFile << "\n"; 
    }

    outFile.close(); 
     cout << "Map data saved to file: " << filename <<  endl;
}

void Map::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

  
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            inFile >> grid[i][j]; 
        }
        inFile.ignore();
    }

    inFile.close(); 
     cout << "Map data loaded from file: " << filename <<  endl;
}
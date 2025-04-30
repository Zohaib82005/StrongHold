// Map.cpp
#include "stronghold.h"
#include <iostream>

Map::Map() {
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            grid[y][x] = '.';
        }
    }
    grid[2][2] = 'K'; // Capital in center
}

void Map::display() const {
    std::cout << "\n=== KINGDOM MAP ===\n";
    for (int y = 0; y < MAP_HEIGHT; ++y) {
        for (int x = 0; x < MAP_WIDTH; ++x) {
            std::cout << grid[y][x] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "=================\n";
}

bool Map::placeBuilding(char buildingType, int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && grid[y][x] == '.') {
        grid[y][x] = buildingType;
        return true;
    }
    std::cout << "[Map] Cannot build there.\n";
    return false;
}
// Map.h
#ifndef MAP_H
#define MAP_H

class Map {
private:
    static const int MAP_WIDTH = 5;
    static const int MAP_HEIGHT = 5;
    char grid[MAP_HEIGHT][MAP_WIDTH];

public:
    Map();
    void display() const;
    bool placeBuilding(char buildingType, int x, int y);
};

#endif
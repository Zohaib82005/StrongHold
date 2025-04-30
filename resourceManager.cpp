#include "stronghold.h"
#include <iostream>

ResourceManager::ResourceManager() {
    food = 200;
    wood = 100;
    stone = 80;
    iron = 50;
}

void ResourceManager::gatherResources(int f, int w, int s, int i) {
    if (f < 0 || w < 0 || s < 0 || i < 0) {
         cout << "Invalid gathering values.\n";
        return;
    }
    food += f;
    wood += w;
    stone += s;
    iron += i;
     cout << "Resources gathered.\n";
}

void ResourceManager::consumeResources(int f, int w, int s, int i) {
    if (f > food || w > wood || s > stone || i > iron) {
         cout << "Not enough resources to consume.\n";
        return;
    }
    food -= f;
    wood -= w;
    stone -= s;
    iron -= i;
     cout << "Resources consumed.\n";
}

void ResourceManager::loseResources(int f, int w, int s, int i) {
    food -= (f > food ? food : f);
    wood -= (w > wood ? wood : w);
    stone -= (s > stone ? stone : s);
    iron -= (i > iron ? iron : i);
     cout << "Resources lost due to disaster.\n";
}

void ResourceManager::displayResources() const {
     cout << "Resources:\n";
     cout << " Food: " << food << "\n";
     cout << " Wood: " << wood << "\n";
     cout << " Stone: " << stone << "\n";
     cout << " Iron: " << iron << "\n";
}

int ResourceManager::getFood() const { return food; }
int ResourceManager::getWood() const { return wood; }
int ResourceManager::getStone() const { return stone; }
int ResourceManager::getIron() const { return iron; }


void ResourceManager::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    
    outFile << food << " " << wood << " " << stone << " " << iron <<  endl;

    outFile.close();
     cout << "Resource data saved to file: " << filename <<  endl;
}

void ResourceManager::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

    
    inFile >> food >> wood >> stone >> iron;

    inFile.close(); 
     cout << "Resource data loaded from file: " << filename <<  endl;
}
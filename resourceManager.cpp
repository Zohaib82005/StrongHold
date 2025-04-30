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
        std::cout << "Invalid gathering values.\n";
        return;
    }
    food += f;
    wood += w;
    stone += s;
    iron += i;
    std::cout << "Resources gathered.\n";
}

void ResourceManager::consumeResources(int f, int w, int s, int i) {
    if (f > food || w > wood || s > stone || i > iron) {
        std::cout << "Not enough resources to consume.\n";
        return;
    }
    food -= f;
    wood -= w;
    stone -= s;
    iron -= i;
    std::cout << "Resources consumed.\n";
}

void ResourceManager::loseResources(int f, int w, int s, int i) {
    food -= (f > food ? food : f);
    wood -= (w > wood ? wood : w);
    stone -= (s > stone ? stone : s);
    iron -= (i > iron ? iron : i);
    std::cout << "Resources lost due to disaster.\n";
}

void ResourceManager::displayResources() const {
    std::cout << "Resources:\n";
    std::cout << " Food: " << food << "\n";
    std::cout << " Wood: " << wood << "\n";
    std::cout << " Stone: " << stone << "\n";
    std::cout << " Iron: " << iron << "\n";
}

int ResourceManager::getFood() const { return food; }
int ResourceManager::getWood() const { return wood; }
int ResourceManager::getStone() const { return stone; }
int ResourceManager::getIron() const { return iron; }

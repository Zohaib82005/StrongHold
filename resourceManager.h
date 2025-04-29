#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

class ResourceManager {
private:
    int food;
    int wood;
    int stone;
    int iron;

public:
    ResourceManager();

    void gatherResources(int f, int w, int s, int i);
    void consumeResources(int f, int w, int s, int i);
    void loseResources(int f, int w, int s, int i);
    void displayResources() const;

    int getFood() const;
    int getWood() const;
    int getStone() const;
    int getIron() const;
};

#endif

#ifndef POPULATION_H
#define POPULATION_H

#include <string>

class Population {
private:
    int peasants;
    int merchants;
    int nobles;
    int ill;
    int revolting;

public:
    Population();

    void simulateGrowth(int foodSupply, int shelterCapacity, int jobsAvailable);
    void applyIllness(int severity);
    void checkForRevolt();

    int getTotalPopulation() const;
    int getWorkingClass() const;
    void displayStatus() const;
};

#endif

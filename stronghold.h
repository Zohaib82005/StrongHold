#ifndef STRONGHOLD_H
#define STRONGHOLD_H

#include <string>
#include <iostream>
#include <fstream> // For file handling
using namespace std;

class Army
{
private:
    int soldiers;
    int morale;
    int corruption;
    int foodSupply;
    int goldSupply;

public:
    Army();

    void recruit(int populationAvailable);
    void train();
    void feedAndPay();
    void displayStatus() const;

    int getStrength() const;

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class Bank
{
private:
    int treasury;
    int outstandingLoan;
    float interestRate;
    bool corruptionDetected;

public:
    Bank();

    void issueLoan(int amount);
    void repayLoan(int amount);
    void applyInterest();
    void auditTreasury();
    void displayStatus() const;

    int getTreasury() const;

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class Economy
{
private:
    int treasury;
    float taxRate; // % of population income
    int inflation;
    bool atWar;

public:
    Economy();

    void collectTaxes(int populationSize);
    void spendOnServices(int amount);
    void declareWar();
    void endWar();
    void applyInflation();
    void displayStatus() const;

    int getTreasury() const;

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class EventManager
{
private:
    string lastEvent; // Description of the last triggered event
    int eventCount;        // Number of events triggered so far

public:
    EventManager();

    void triggerRandomEvent();

     
    void saveToFile(const  string& filename) const;
    void loadFromFile(const  string& filename);

    // Getters (optional)
    string getLastEvent() const;
    int getEventCount() const;
};

class Leadership
{
private:
    string currentLeader;
    string policy;
    int popularity;
    bool inPower;

public:
    Leadership();

    void holdElection(const  string& newLeader);
    void initiateCoup();
    void changePolicy(const  string& newPolicy);
    void assessStability();
    void displayStatus() const;
    string getPolicy() const;
    bool isInPower() const;

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class Map
{
private:
    static const int MAP_WIDTH = 5;
    static const int MAP_HEIGHT = 5;
    char grid[MAP_HEIGHT][MAP_WIDTH];

public:
    Map();
    void display() const;
    bool placeBuilding(char buildingType, int x, int y);

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class Population
{
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

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

class ResourceManager
{
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

     
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
#ifndef ECONOMY_H
#define ECONOMY_H

class Economy {
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
};

#endif

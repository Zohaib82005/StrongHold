#ifndef ARMY_H
#define ARMY_H

class Army {
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
};

#endif

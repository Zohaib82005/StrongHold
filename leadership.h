#ifndef LEADERSHIP_H
#define LEADERSHIP_H

#include <string>

class Leadership {
private:
    std::string currentLeader;
    std::string policy;
    int popularity;
    bool inPower;

public:
    Leadership();

    void holdElection(const std::string& newLeader);
    void initiateCoup();
    void changePolicy(const std::string& newPolicy);
    void assessStability();

    void displayStatus() const;
    std::string getPolicy() const;
    bool isInPower() const;
};

#endif

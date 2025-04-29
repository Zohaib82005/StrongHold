#ifndef BANK_H
#define BANK_H

class Bank {
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
};

#endif

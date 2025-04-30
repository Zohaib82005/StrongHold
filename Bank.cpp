#include "stronghold.h"
#include <iostream>
#include <cstdlib> // for rand()

Bank::Bank() {
    treasury = 500;
    outstandingLoan = 0;
    interestRate = 0.10f; // 10%
    corruptionDetected = false;
}

void Bank::issueLoan(int amount) {
    if (amount <= 0) {
        std::cout << "Invalid loan amount.\n";
        return;
    }
    outstandingLoan += amount;
    treasury += amount;
    std::cout << "Loan issued: " << amount << " gold.\n";
}

void Bank::repayLoan(int amount) {
    if (amount <= 0 || amount > treasury) {
        std::cout << "Cannot repay loan. Invalid amount or insufficient treasury.\n";
        return;
    }
    if (amount > outstandingLoan) amount = outstandingLoan;
    treasury -= amount;
    outstandingLoan -= amount;
    std::cout << "Repaid loan: " << amount << " gold.\n";
}

void Bank::applyInterest() {
    if (outstandingLoan > 0) {
        int interest = static_cast<int>(outstandingLoan * interestRate);
        outstandingLoan += interest;
        std::cout << "Interest applied: +" << interest << " gold to loan.\n";
    }
}

void Bank::auditTreasury() {
    int chance = rand() % 100;
    if (chance < 20) {
        corruptionDetected = true;
        int loss = treasury / 10;
        treasury -= loss;
        std::cout << "Corruption detected! " << loss << " gold lost.\n";
    }
    else {
        std::cout << "Audit clean. No corruption found.\n";
    }
}

int Bank::getTreasury() const {
    return treasury;
}

void Bank::displayStatus() const {
    std::cout << "Bank Status:\n";
    std::cout << " Treasury: " << treasury << " gold\n";
    std::cout << " Outstanding Loan: " << outstandingLoan << " gold\n";
    std::cout << " Interest Rate: " << interestRate * 100 << "%\n";
    std::cout << " Corruption: " << (corruptionDetected ? "Yes" : "No") << "\n";
}

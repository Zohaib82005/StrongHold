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
         cout << "Invalid loan amount.\n";
        return;
    }
    outstandingLoan += amount;
    treasury += amount;
     cout << "Loan issued: " << amount << " gold.\n";
}

void Bank::repayLoan(int amount) {
    if (amount <= 0 || amount > treasury) {
         cout << "Cannot repay loan. Invalid amount or insufficient treasury.\n";
        return;
    }
    if (amount > outstandingLoan) amount = outstandingLoan;
    treasury -= amount;
    outstandingLoan -= amount;
     cout << "Repaid loan: " << amount << " gold.\n";
}

void Bank::applyInterest() {
    if (outstandingLoan > 0) {
        int interest = static_cast<int>(outstandingLoan * interestRate);
        outstandingLoan += interest;
         cout << "Interest applied: +" << interest << " gold to loan.\n";
    }
}

void Bank::auditTreasury() {
    int chance = rand() % 100;
    if (chance < 20) {
        corruptionDetected = true;
        int loss = treasury / 10;
        treasury -= loss;
         cout << "Corruption detected! " << loss << " gold lost.\n";
    }
    else {
         cout << "Audit clean. No corruption found.\n";
    }
}

int Bank::getTreasury() const {
    return treasury;
}

void Bank::displayStatus() const {
     cout << "Bank Status:\n";
     cout << " Treasury: " << treasury << " gold\n";
     cout << " Outstanding Loan: " << outstandingLoan << " gold\n";
     cout << " Interest Rate: " << interestRate * 100 << "%\n";
     cout << " Corruption: " << (corruptionDetected ? "Yes" : "No") << "\n";
}

void Bank::loadFromFile(const  string& filename) {
     ifstream inFile(filename); 
    if (!inFile.is_open()) {
         cerr << "Error: Unable to open file for loading: " << filename <<  endl;
        return; 
    }

   
    int corruptionFlag; 
    inFile >> treasury >> outstandingLoan >> interestRate >> corruptionFlag;

   
    corruptionDetected = (corruptionFlag == 1);

    inFile.close(); 
     cout << "Bank data loaded from file: " << filename <<  endl;
}

void Bank::saveToFile(const  string& filename) const {
     ofstream outFile(filename); 
    if (!outFile.is_open()) {
         cerr << "Error: Unable to open file for saving: " << filename <<  endl;
        return; 
    }

    
    outFile << treasury << " " << outstandingLoan << " " << interestRate << " "
        << (corruptionDetected ? 1 : 0) <<  endl;

    outFile.close();
     cout << "Bank data saved to file: " << filename <<  endl;
}
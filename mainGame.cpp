#include <iostream>
#include <string>
#include "Population.h"
#include "Army.h"
#include "Leadership.h"
#include "Economy.h"
#include "Bank.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "Map.h" // Include the new map class

int main() {
    Population population;
    Army army;
    Leadership leadership;
    Economy economy;
    Bank bank;
    ResourceManager resources;
    EventManager events;
    Map kingdomMap;

    std::cout << "=== STRONGHOLD: KINGDOM SIMULATION STARTED ===\n";

    const int maxTurns = 5;
    for (int turn = 1; turn <= maxTurns; ++turn) {
        std::cout << "\n--- SEASON " << turn << " ---\n";

        // Display current status
        population.displayStatus();
        army.displayStatus();
        leadership.displayStatus();
        economy.displayStatus();
        bank.displayStatus();
        resources.displayResources();
        kingdomMap.display();

        // ==== PLAYER MENU ====
        std::cout << "\nWhat would you like to do this season?\n";
        std::cout << "1. Collect taxes\n";
        std::cout << "2. Recruit soldiers\n";
        std::cout << "3. Train army\n";
        std::cout << "4. Build structure on map\n";
        std::cout << "5. Spend on services\n";
        std::cout << "6. Change policy\n";
        std::cout << "7. Do nothing\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            economy.collectTaxes(population.getTotalPopulation());
            break;
        case 2:
            army.recruit(population.getWorkingClass());
            break;
        case 3:
            army.train();
            break;
        case 4: {
            char building;
            int x, y;
            std::cout << "Enter building type (F=Farm, M=Mine, W=Wall, B=Barracks): ";
            std::cin >> building;
            std::cout << "Enter coordinates (x y): ";
            std::cin >> x >> y;
            kingdomMap.placeBuilding(building, x, y);
            break;
        }
        case 5: {
            int amount;
            std::cout << "How much gold to spend on services? ";
            std::cin >> amount;
            economy.spendOnServices(amount);
            break;
        }
        case 6:
            leadership.changePolicy("Reformist");
            break;
        case 7:
            std::cout << "You chose to do nothing this season.\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
        }

        // Background simulation
        population.simulateGrowth(resources.getFood(), 300, 200);
        army.feedAndPay();
        economy.applyInflation();
        bank.applyInterest();
        bank.auditTreasury();
        resources.gatherResources(30, 20, 15, 10);
        resources.consumeResources(50, 10, 5, 3);

        // Random event
        std::cout << "\n[EVENT] Something is happening...\n";
        events.triggerRandomEvent();

        // Ask how to respond
        std::cout << "How will you respond? (1: Use funds, 2: Ignore, 3: Draft citizens)\n";
        int response;
        std::cin >> response;

        switch (response) {
        case 1:
            bank.repayLoan(100); // Example cost
            population.applyIllness(10);
            break;
        case 2:
            population.checkForRevolt();
            break;
        case 3:
            army.recruit(population.getWorkingClass());
            break;
        default:
            std::cout << "No effective action taken.\n";
        }

        // Stability check
        leadership.assessStability();
        population.applyIllness(turn);
    }

    std::cout << "\n=== GAME OVER: Final Kingdom Report ===\n";
    population.displayStatus();
    army.displayStatus();
    leadership.displayStatus();
    economy.displayStatus();
    bank.displayStatus();
    resources.displayResources();
    kingdomMap.display();

    return 0;
}
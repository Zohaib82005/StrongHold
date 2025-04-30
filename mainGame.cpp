#include <iostream>
#include <string>
#include "stronghold.h"

int main() {
    Population population;
    Army army;
    Leadership leadership;
    Economy economy;
    Bank bank;
    ResourceManager resources;
    EventManager events;
    Map kingdomMap;

     cout << "=== STRONGHOLD: KINGDOM SIMULATION STARTED ===\n";

    const int maxTurns = 5;
    for (int turn = 1; turn <= maxTurns; ++turn) {
         cout << "\n--- SEASON " << turn << " ---\n";

        // Display current status
        population.displayStatus();
        army.displayStatus();
        leadership.displayStatus();
        economy.displayStatus();
        bank.displayStatus();
        resources.displayResources();
        kingdomMap.display();

        // ==== PLAYER MENU ====
         cout << "\nWhat would you like to do this season?\n";
         cout << "1. Collect taxes\n";
         cout << "2. Recruit soldiers\n";
         cout << "3. Train army\n";
         cout << "4. Build structure on map\n";
         cout << "5. Spend on services\n";
         cout << "6. Change policy\n";
         cout << "7. Save Game\n"; // Added option to save game
         cout << "8. Load Game\n"; // Added option to load game
         cout << "9. Do nothing\n";
        int choice;
         cin >> choice;

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
             cout << "Enter building type (F=Farm, M=Mine, W=Wall, B=Barracks): ";
             cin >> building;
             cout << "Enter coordinates (x y): ";
             cin >> x >> y;
            kingdomMap.placeBuilding(building, x, y);
            break;
        }
        case 5: {
            int amount;
             cout << "How much gold to spend on services? ";
             cin >> amount;
            economy.spendOnServices(amount);
            break;
        }
        case 6:
            leadership.changePolicy("Reformist");
            break;
        case 7: {
            // Save all objects to files
             cout << "Saving game...\n";
            population.saveToFile("population_data.txt");
            army.saveToFile("army_data.txt");
            leadership.saveToFile("leadership_data.txt");
            economy.saveToFile("economy_data.txt");
            bank.saveToFile("bank_data.txt");
            resources.saveToFile("resources_data.txt");
            kingdomMap.saveToFile("map_data.txt");
             cout << "Game saved successfully!\n";
            break;
        }
        case 8: {
            // Load all objects from files
             cout << "Loading game...\n";
            population.loadFromFile("population_data.txt");
            army.loadFromFile("army_data.txt");
            leadership.loadFromFile("leadership_data.txt");
            economy.loadFromFile("economy_data.txt");
            bank.loadFromFile("bank_data.txt");
            resources.loadFromFile("resources_data.txt");
            kingdomMap.loadFromFile("map_data.txt");
             cout << "Game loaded successfully!\n";
            break;
        }
        case 9:
             cout << "You chose to do nothing this season.\n";
            break;
        default:
             cout << "Invalid choice.\n";
        }

        
        population.simulateGrowth(resources.getFood(), 300, 200);
        army.feedAndPay();
        economy.applyInflation();
        bank.applyInterest();
        bank.auditTreasury();
        resources.gatherResources(30, 20, 15, 10);
        resources.consumeResources(50, 10, 5, 3);

       
         cout << "\n[EVENT] Something is happening...\n";
        events.triggerRandomEvent();

       
         cout << "How will you respond? (1: Use funds, 2: Ignore, 3: Draft citizens)\n";
        int response;
         cin >> response;

        switch (response) {
        case 1:
            bank.repayLoan(100); 
            population.applyIllness(10);
            break;
        case 2:
            population.checkForRevolt();
            break;
        case 3:
            army.recruit(population.getWorkingClass());
            break;
        default:
             cout << "No effective action taken.\n";
        }

       
        leadership.assessStability();
        population.applyIllness(turn);
    }

     cout << "\n=== GAME OVER: Final Kingdom Report ===\n";
    population.displayStatus();
    army.displayStatus();
    leadership.displayStatus();
    economy.displayStatus();
    bank.displayStatus();
    resources.displayResources();
    kingdomMap.display();

    return 0;
}
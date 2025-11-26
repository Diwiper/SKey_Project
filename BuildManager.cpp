#include "BuildManager.h"
#include <fstream>
#include <iostream>

BuildManager::BuildManager() : totalPrice(0.0) {}

BuildManager::~BuildManager() {
    for (Component* c : currentBuild) {
        delete c; // Видаляємо об'єкти, щоб не було витоку пам'яті
    }
    currentBuild.clear();
}

void BuildManager::addComponent(Component* c) {
    currentBuild.push_back(c);
    totalPrice += c->getPrice();
    cout << "Added: " << c->getName() << ". New Total: $" << totalPrice << endl;
}

void BuildManager::removeComponent(int index) {
    if (index >= 0 && index < currentBuild.size()) {
        Component* c = currentBuild[index];
        totalPrice -= c->getPrice();
        cout << "Removed: " << c->getName() << endl;

        delete c; // Видаляємо об'єкт з пам'яті
        currentBuild.erase(currentBuild.begin() + index); // Видаляємо з вектора
    }
    else {
        cout << "Error: Invalid index!" << endl;
    }
}

void BuildManager::saveConfig() {
    ofstream file("SKey_Configuration.txt");
    if (file.is_open()) {
        file << "=== SKey Build Configuration ===\n";
        for (const auto& c : currentBuild) {
            file << c->getType() << ": " << c->getName()
                << " - $" << c->getPrice() << "\n";
        }
        file << "-----------------------------\n";
        file << "TOTAL PRICE: $" << totalPrice << "\n";
        file.close();
        cout << "Configuration saved to 'SKey_Configuration.txt'" << endl;
    }
    else {
        cout << "Error opening file for save!" << endl;
    }
}

void BuildManager::printReport() const {
    cout << "\n--- Current Build ---" << endl;
    for (size_t i = 0; i < currentBuild.size(); ++i) {
        cout << i << ". ";
        currentBuild[i]->printInfo();
    }
    cout << "Total Price: $" << totalPrice << endl;
    cout << "---------------------" << endl;
}
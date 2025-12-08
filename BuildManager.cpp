#include "BuildManager.h"
#include "Components.h"
#include <fstream>
#include <iostream>

BuildManager::BuildManager() : totalPrice(0.0) {}

BuildManager::~BuildManager() {
    for (Component* c : currentBuild) {
        delete c;
    }
    currentBuild.clear();
}

void BuildManager::addComponent(Component* c) {
    Component* currentCasePtr = nullptr;
    for (Component* existing : currentBuild) {
        if (existing->getType() == "Case") {
            currentCasePtr = existing;
            break;
        }
    }

    if (c->getType() == "PCB" && currentCasePtr != nullptr) {
        Case* myCase = static_cast<Case*>(currentCasePtr);
        PCB* myPcb = static_cast<PCB*>(c);

        string caseFF = myCase->getFormFactor();
        string pcbLayout = myPcb->getSupportedLayout();

        if (caseFF != pcbLayout) {
            cout << "\n[ERROR] Incompatible Component!" << endl;
            cout << "Cannot add PCB (" << pcbLayout << ") into Case (" << caseFF << ")." << endl;
            cout << "Component rejected.\n" << endl;
            return;
        }
    }

    currentBuild.push_back(c);
    totalPrice += c->getPrice();
    cout << "Added: " << c->getName() << ". New Total: $" << totalPrice << endl;
}

void BuildManager::removeComponent(int index) {
    if (index >= 0 && index < currentBuild.size()) {
        Component* c = currentBuild[index];
        totalPrice -= c->getPrice();
        cout << "Removed: " << c->getName() << endl;

        delete c;
        currentBuild.erase(currentBuild.begin() + index);
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
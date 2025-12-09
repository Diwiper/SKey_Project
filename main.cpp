#include <iostream>
#include <limits> // For input buffer clearing
#include <string>
#include "BuildManager.h"
#include "Components.h"

using namespace std;

// Helper function to clear the input stream (fixes getline issues after cin >>)
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Wizard functions for adding components via console
void addCaseWizard(BuildManager& manager) {
    string name, manuf, formFactor, mountType, color, plateMat;
    double price;

    cout << "\n--- Add Case ---\n";
    cout << "Name: "; clearInput(); getline(cin, name);
    cout << "Manufacturer: "; getline(cin, manuf);
    cout << "Price: "; cin >> price;
    cout << "Form Factor (e.g., 60%): "; clearInput(); getline(cin, formFactor);
    cout << "Mount Type (e.g., Tray): "; getline(cin, mountType);
    cout << "Color: "; getline(cin, color);
    cout << "Plate Material: "; getline(cin, plateMat);

    manager.addComponent(new Case(name, price, manuf, formFactor, mountType, color, plateMat));
    cout << ">> Case added successfully!\n";
}

void addPCBWizard(BuildManager& manager) {
    string name, manuf, socketType, layout;
    double price;
    bool hasRGB;

    cout << "\n--- Add PCB ---\n";
    cout << "Name: "; clearInput(); getline(cin, name);
    cout << "Manufacturer: "; getline(cin, manuf);
    cout << "Price: "; cin >> price;
    cout << "Socket Type (e.g., Hotswap): "; clearInput(); getline(cin, socketType);
    cout << "Has RGB (1 for Yes, 0 for No): "; cin >> hasRGB;
    cout << "Supported Layout (e.g., TKL): "; clearInput(); getline(cin, layout);

    manager.addComponent(new PCB(name, price, manuf, socketType, hasRGB, layout));
    cout << ">> PCB added successfully!\n";
}

void addSwitchWizard(BuildManager& manager) {
    string name, manuf, swType;
    double price;
    int force;

    cout << "\n--- Add Switch ---\n";
    cout << "Name: "; clearInput(); getline(cin, name);
    cout << "Manufacturer: "; getline(cin, manuf);
    cout << "Price: "; cin >> price;
    cout << "Type (Linear/Tactile/Clicky): "; clearInput(); getline(cin, swType);
    cout << "Actuation Force (g): "; cin >> force;

    manager.addComponent(new Switch(name, price, manuf, swType, force));
    cout << ">> Switch added successfully!\n";
}

void addKeycapWizard(BuildManager& manager) {
    string name, manuf, profile, material, language;
    double price;

    cout << "\n--- Add Keycaps ---\n";
    cout << "Name: "; clearInput(); getline(cin, name);
    cout << "Manufacturer: "; getline(cin, manuf);
    cout << "Price: "; cin >> price;
    cout << "Profile (Cherry/OEM): "; clearInput(); getline(cin, profile);
    cout << "Material (PBT/ABS): "; getline(cin, material);
    cout << "Language: "; getline(cin, language);

    manager.addComponent(new Keycap(name, price, manuf, profile, material, language));
    cout << ">> Keycaps added successfully!\n";
}

int main() {
    cout << "Welcome to SKey System v2.0" << endl;

    BuildManager manager;
    bool isRunning = true;
    int choice;

    // Pre-load some test data (optional)
    manager.addComponent(new Case("Tofu60", 120.0, "KBDFans", "60%", "Tray", "Black", "Brass"));

    while (isRunning) {
        cout << "\n================ MENU ================" << endl;
        cout << "1. Show Report" << endl;
        cout << "2. Add Component" << endl;
        cout << "3. Remove Component" << endl;
        cout << "4. Save Configuration" << endl;
        cout << "0. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) { // Validate input
            cout << "Invalid input! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            manager.printReport();
            break;
        case 2: {
            int typeChoice;
            cout << "\nSelect component type:\n1-Case, 2-PCB, 3-Switch, 4-Keycap: ";
            cin >> typeChoice;
            if (typeChoice == 1) addCaseWizard(manager);
            else if (typeChoice == 2) addPCBWizard(manager);
            else if (typeChoice == 3) addSwitchWizard(manager);
            else if (typeChoice == 4) addKeycapWizard(manager);
            else cout << "Invalid component type.\n";
            break;
        }
        case 3: {
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            // Assuming removeComponent takes an int index
            manager.removeComponent(index);
            cout << ">> Removal operation executed.\n";
            break;
        }
        case 4:
            manager.saveConfig();
            cout << ">> Configuration saved to file.\n";
            break;
        case 0:
            isRunning = false;
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Unknown command." << endl;
        }
    }

    // Pause before closing the window
    cout << "\nPress Enter to close window...";
    clearInput();
    cin.get();

    return 0;
}
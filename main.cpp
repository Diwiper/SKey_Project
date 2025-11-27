#include <iostream>
#include "BuildManager.h"
#include "Components.h"

using namespace std;

int main() {
    cout << "Welcome to SKey System" << endl;

    BuildManager manager;

    // Case: name, price, manufacturer, formFactor, mountType, color, plateMaterial
    Component* c1 = new Case("Tofu60", 120.0, "KBDFans", "60%", "Tray", "Black", "Brass");

    // PCB: name, price, manufacturer, socketType, hasRGB, supportedLayout
    Component* c2 = new PCB("DZ60RGB", 55.0, "KBDFans", "Hotswap", true, "60%");

    // Switch: name, price, manufacturer, switchType, actuationForce
    Component* c3 = new Switch("Gateron Yellow", 25.0, "Gateron", "Linear", 50);

    // Keycap: name, price, manufacturer, profile, material, language
    Component* c4 = new Keycap("PBTfans WoB", 75.0, "PBTfans", "Cherry", "PBT", "ENG");

    manager.addComponent(c1);
    manager.addComponent(c2);
    manager.addComponent(c3);
    manager.addComponent(c4);

    manager.printReport();

    manager.removeComponent(2);

    manager.saveConfig();

    return 0;
}
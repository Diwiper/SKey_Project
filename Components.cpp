#include "Components.h"

// --- Component ---
Component::Component(string n, double p, string m) : name(n), price(p), manufacturer(m) {}
Component::~Component() {}

string Component::getName() const { return name; }
double Component::getPrice() const { return price; }
string Component::getManufacturer() const { return manufacturer; }

void Component::printInfo() const {cout << name << " (" << manufacturer << ") - $" << price;}

// --- Case ---
Case::Case(string n, double p, string m, string ff, string mt, string c, string pm)
    : Component(n, p, m), formFactor(ff), mountType(mt), color(c), plateMaterial(pm) {
}

void Case::printInfo() const {
    cout << "[CASE] ";
    Component::printInfo();
    cout << " | FF: " << formFactor << ", Mount: " << mountType
        << ", Color: " << color << ", Plate: " << plateMaterial << endl;
}
string Case::getType() const { return "Case"; }

// --- PCB ---
PCB::PCB(string n, double p, string m, string st, bool rgb, string sl)
    : Component(n, p, m), socketType(st), hasRGB(rgb), supportedLayout(sl) {
}

void PCB::printInfo() const {
    cout << "[PCB] ";
    Component::printInfo();
    cout << " | Socket: " << socketType << ", RGB: " << (hasRGB ? "Yes" : "No")
        << ", Layout: " << supportedLayout << endl;
}
string PCB::getType() const { return "PCB"; }

// --- Switch ---
Switch::Switch(string n, double p, string m, string st, int af)
    : Component(n, p, m), switchType(st), actuationForce(af) {
}

void Switch::printInfo() const {
    cout << "[SWITCH] ";
    Component::printInfo();
    cout << " | Type: " << switchType << ", Force: " << actuationForce << "g" << endl;
}
string Switch::getType() const { return "Switch"; }

// --- Keycap ---
Keycap::Keycap(string n, double p, string m, string prof, string mat, string lang)
    : Component(n, p, m), profile(prof), material(mat), language(lang) {
}

void Keycap::printInfo() const {
    cout << "[KEYCAP] ";
    Component::printInfo();
    cout << " | Profile: " << profile << ", Material: " << material
        << ", Lang: " << language << endl;
}
string Keycap::getType() const { return "Keycap"; }
#include "Components.h"

// --- Component ---
Component::Component(string n, double p, string m) : name(n), price(p), manufacturer(m) {}
Component::~Component() {}

string Component::getName() const { return name; }
double Component::getPrice() const { return price; }
string Component::getManufacturer() const { return manufacturer; }

void Component::printInfo() const {cout << name << " (" << manufacturer << ") - $" << price;}


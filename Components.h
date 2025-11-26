#pragma once
#include <string>
#include <iostream>

using namespace std;

// --- Базовий клас Component ---
class Component {
protected:
    string name;
    double price;
    string manufacturer;

public:
    Component(string n, double p, string m);
    virtual ~Component(); 

    string getName() const;
    double getPrice() const;
    string getManufacturer() const;


    virtual void printInfo() const;
    virtual string getType() const = 0; 
};

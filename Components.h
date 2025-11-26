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

// --- Клас Case (Корпус) ---
class Case : public Component {
private:
    string formFactor;
    string mountType;
    string color;
    string plateMaterial;

public:
    Case(string n, double p, string m, string ff, string mt, string c, string pm);
    void printInfo() const override;
    string getType() const override;
};

// --- Клас PCB (Плата) ---
class PCB : public Component {
private:
    string socketType;
    bool hasRGB;
    string supportedLayout;

public:
    PCB(string n, double p, string m, string st, bool rgb, string sl);
    void printInfo() const override;
    string getType() const override;
};

// --- Клас Switch (Світчі) ---
class Switch : public Component {
private:
    string switchType;
    int actuationForce;

public:
    Switch(string n, double p, string m, string st, int af);
    void printInfo() const override;
    string getType() const override;
};

// --- Клас Keycap (Кейкапи) ---
class Keycap : public Component {
private:
    string profile;
    string material;
    string language;

public:
    Keycap(string n, double p, string m, string prof, string mat, string lang);
    void printInfo() const override;
    string getType() const override;
};
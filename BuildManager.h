#pragma once
#include <vector>
#include "Components.h"

class BuildManager {
private:
    vector<Component*> currentBuild; // Агрегація компонентів
    double totalPrice;

public:
    BuildManager();
    ~BuildManager(); 

    void addComponent(Component* c);
    void removeComponent(int index);
    void saveConfig(); // Збереження у файл

    void printReport() const;
};
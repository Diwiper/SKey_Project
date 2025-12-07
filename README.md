# SKey Project ⌨️

**SKey** is a C++ console application designed to automate the selection of components for custom mechanical keyboards. The program allows users to create a virtual build, calculate the total cost, and save the configuration to a file.

## 🚀 Features
* **Component Modeling:** Implements `Case`, `PCB`, `Switch`, and `Keycap` classes derived from the abstract `Component` base class.
* **Build Manager:** Allows adding and removing components with automatic total price calculation (`TotalPrice`).
* **Data Persistence:** Exports the final build configuration to a text file (`SKey_Configuration.txt`).
* **OOP Principles:** Demonstrates inheritance, polymorphism, and encapsulation.

## 🛠 Tech Stack
* **Language:** C++ (Standard C++17)
* **IDE:** Microsoft Visual Studio 2022
* **Version Control:** Git / GitHub

## 📂 Project Structure
* `main.cpp` — Entry point, demonstration of the main logic.
* `Components.h / .cpp` — Definitions of the component class hierarchy.
* `BuildManager.h / .cpp` — Build management and business logic.

## ⚙️ How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/Diwiper/SKeyProject.git](https://github.com/Diwiper/SKeyProject.git)
    ```
2.  Open the solution file `SKey.sln` in **Visual Studio**.
3.  Build and Run the project (`Ctrl + F5`).


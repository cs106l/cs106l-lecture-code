/* File: pirate.cpp
 * Author: Preston Seay
 *
 * This file defines AND implements a Pirate class (typically, we'd want
 * to define it in a header file and implement it here, but for the exercise,
 * I've put it into one file so it's quick to see it all in one place).
 * 
 * Each pirate has a treasure. You are going to implement the pirate class
 * so that pirates get their own treasure even when copied.
 */
#include <iostream>
#include <string>

class Treasure {
public:
    std::string name;
    int goldValue;

    Treasure(std::string name, int goldValue)
        : name(name), goldValue(goldValue) {}
};

class Pirate {
private:
    Treasure* treasure;

public:
    // TODO:
    // Implement the Big Four:
    //
    // 1. Default constructor
    //    - Create a Treasure on the heap named "Rusty Spoon" (similar to line 45)
    //    - Worth 1 gold
    //
    // 2. Copy constructor
    //    - Must DEEP COPY the Treasure
    //
    // 3. Copy assignment operator
    //    - Must DEEP COPY the Treasure
    //    - Must correctly handle self-assignment
    //
    // 4. Destructor
    //    - Must free heap memory
    //
    // Why heap allocation here?
    // Pirates own Treasure objects dynamically.
    // If two Pirates accidentally share the same Treasure pointer,
    // modifying or deleting one causes serious bugs.

    Pirate() {
        // TODO
    }

    Pirate(std::string itemName, int value) {
        treasure = new Treasure(itemName, value);
    }

    Pirate(const Pirate& other) {
        // TODO
    }

    Pirate& operator=(const Pirate& other) {
        // TODO
        return *this;
    }

    ~Pirate() {
        // TODO
    }

    void renameTreasure(std::string newName) {
        treasure->name = newName;
    }

    void upgradeTreasure(int extraGold) {
        treasure->goldValue += extraGold;
    }

    void print() const {
        std::cout
            << treasure->name
            << " worth "
            << treasure->goldValue
            << " gold\n";
    }
};

void inspectPirate(Pirate p) {
    std::cout << "Inspecting pirate treasure: ";
    p.print();
}

int main() {
    std::cout << "Creating default pirate...\n";
    Pirate a;
    a.print();

    std::cout << "\nCreating custom pirate...\n";
    Pirate b("Golden Crown", 500);
    b.print();

    std::cout << "\nTesting copy constructor...\n";
    Pirate c = b;

    c.renameTreasure("Fake Crown");
    c.upgradeTreasure(-400);

    std::cout << "Original pirate:\n";
    b.print();

    std::cout << "Copied pirate:\n";
    c.print();

    std::cout << "\nTesting copy assignment...\n";
    Pirate d("Broken Bottle", 2);

    d = b;

    d.renameTreasure("Stolen Crown");
    d.upgradeTreasure(300);

    std::cout << "Original pirate:\n";
    b.print();

    std::cout << "Assigned pirate:\n";
    d.print();

    std::cout << "\nPassing pirate by value...\n";
    inspectPirate(b);

    std::cout << "\nTesting self-assignment...\n";
    b = b;
    b.print();

    std::cout << "\nEnd of program.\n";
}
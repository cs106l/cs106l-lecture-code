#include <iostream>
#include <string>

class Treasure {
public:
    std::string name;
    int gold;

    Treasure(std::string n, int g) : name(n), gold(g) {}
};

class Pirate {
private:
    Treasure* loot;

public:
    // TODO:
    // Implement:
    // 1. Move constructor
    //    - Take the other pirate's loot.
    //    - Give them an empty chest or nullptr for their loot.
    // 2. Move assignment operator
    //    - Get rid of your own loot.
    //    - Take the other pirate's loot.
    //    - Give them an empty chest or nullptr for their loot.
    // 3. Delete the copy constructor and copy assignment operator

    Pirate() {
        loot = new Treasure("Empty Chest", 0);
    }

    Pirate(std::string name, int gold) {
        loot = new Treasure(name, gold);
    }

    Pirate(Pirate&& other) noexcept {
        // TODO
    }

    Pirate& operator=(Pirate&& other) noexcept {
        // TODO
        return *this;
    }

    ~Pirate() {
        delete loot;
    }

    void print() const {
        std::cout << loot->name << " (" << loot->gold << " gold)\n";
    }
};

int main() {
    std::cout << "Creating pirate A...\n";
    Pirate a("Blackbeard", 500);

    std::cout << "Creating pirate B...\n";
    Pirate b;

    std::cout << "\nMoving A into B...\n";
    b = std::move(a);

    std::cout << "B now has: ";
    b.print();

    std::cout << "A is now in a valid empty state\n";

    std::cout << "End\n";
}
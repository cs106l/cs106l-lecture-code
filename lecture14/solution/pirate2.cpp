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
    Pirate(Pirate& other) = delete;
    Pirate& operator=(Pirate& other) = delete;

    Pirate() {
        loot = new Treasure("Empty Chest", 0);
    }

    Pirate(std::string name, int gold) {
        loot = new Treasure(name, gold);
    }

    Pirate(Pirate&& other) {
        loot = other.loot;
        other.loot = new Treasure("Empty Chest", 0);
    }

    Pirate& operator=(Pirate&& other) {
        if (this == &other) return *this;

        delete loot;

        loot = other.loot;
        other.loot = new Treasure("Empty Chest", 0);

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

    std::cout << "End\n";
}
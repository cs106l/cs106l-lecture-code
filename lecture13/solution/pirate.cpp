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
    // Default constructor
    Pirate() {
        treasure = new Treasure("Rusty Spoon", 1);

        std::cout << "[Default constructor]\n";
    }

    Pirate(std::string itemName, int value) {
        treasure = new Treasure(itemName, value);

        std::cout << "[Custom constructor]\n";
    }

    // Copy constructor
    Pirate(const Pirate& other) {
        treasure = new Treasure(
            other.treasure->name,
            other.treasure->goldValue
        );

        std::cout << "[Copy constructor]\n";
    }

    // Copy assignment operator
    Pirate& operator=(const Pirate& other) {

        if (this == &other) {
            return *this;
        }

        delete treasure;

        treasure = new Treasure(
            other.treasure->name,
            other.treasure->goldValue
        );

        std::cout << "[Copy assignment]\n";
        return *this;
    }

    // Destructor
    ~Pirate() {
        std::cout << "[Destructor]\n";

        delete treasure;
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
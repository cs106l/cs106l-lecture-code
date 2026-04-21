/* File: wizard-soln.cpp
 * Author: Preston Seay
 * 
 * This file contains an example implementation for a wizard
 * and spellbook class, as well as provides a main function
 * that can run some methods of the classes for you.
 */
#include <iostream>
#include <string>
#include <map>

// WIZARD.H is here, so the solution can all be one file :)
class Wizard {
private:
    std::string name;
    int energy;

public:
    Wizard(const std::string& name, int energy);

    bool useEnergy(int amount);
    int getEnergy() const;
    std::string getName() const;
};

class SpellBook {
private:
    std::map<std::string, int> spells; // spell -> cost

public:
    void addSpell(const std::string& name, int cost);
    void castAll(Wizard& w); // iterate over map and try to cast everything
};

// ==========================
// =     CLASS 1: Wizard    =
// ==========================

// This constructor creates a new wizard, storing it's name
// and starting energy.
Wizard::Wizard(const std::string& name, int energy):
  name{name}, energy{energy} { } // Yay, we can use initializer lists :)

// This function will try to use `amount` of energy.
// If the wizard has enough energy to decrease by
// amount and still be non-zero, then it will subtract
// from energy and return true. Otherwise, the energy
// should remain unchanged and it will return false.
bool Wizard::useEnergy(int amount) {
    if (energy >= amount) {
        energy -= amount;
        return true;
    }
    return false;
}

// This function should simply return the amount of energy
// the wizard has left.
int Wizard::getEnergy() const {
    return energy;
}

// This should simply return the name of the wizard.
std::string Wizard::getName() const {
    return name;
}

// ==========================
// =   CLASS 2: SpellBook   =
// ==========================

// Add this spell to the spellbook.
void SpellBook::addSpell(const std::string& name, int cost) {
    spells[name] = cost;
}

// Try to have the wizard cast all of the spells they can.
void SpellBook::castAll(Wizard& w) {
    for (const auto& [spell, cost] : spells) {
        if (w.useEnergy(cost)) {
            std::cout << w.getName() << " casts " << spell << std::endl;
        } else {
            std::cout << w.getName() << " was too tired to cast " << spell << std::endl;
        }
    }
}

// ==========================
// =        MAIN TEST       =
// ==========================
int main() {
    Wizard w("Merlin", 50);
    SpellBook book;

    book.addSpell("Fireball", 20);
    book.addSpell("Ice", 35);
    book.addSpell("Storm", 15);

    book.castAll(w);

    std::cout << w.getName()
              << " has " << w.getEnergy()
              << " energy left\n";
}
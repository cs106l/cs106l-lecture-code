/* File: wizard.h
 * Author: Preston Seay
 *
 * This file defines a Wizard and a SpellBook class.
 * The wizard has a certain amount of energy, and each spellbook
 * requires a certain amount of energy to cast.
 * 
 * Note that the energy level of the wizard is private because
 * we don't want anyone to be able to change that and it can be
 * non negative and decrease. That's called encapsulation.
 * 
 */
#include <iostream>
#include <string>
#include <map>

class Wizard {
private:
    std::string name;
    int energy;

public:
    Wizard(const std::string& name, int energy);

    bool useEnergy(int amount);   // subtract if possible, return success
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
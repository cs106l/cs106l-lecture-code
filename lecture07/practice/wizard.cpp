/* File: wizard.cpp
 * Author: Preston Seay
 * 
 * This file contains practice for implementing a wizard
 * and spellbook class, as well as provides a main function
 * that can run some methods of the classes for you.
 * 
 * As an exercise, implement the wizard and spellbook
 * classes and compile and run the program.
 */
#include <iostream>
#include <string>
#include <map>
#include "wizard.h"

// ==========================
// =     CLASS 1: Wizard    =
// ==========================

// This constructor creates a new wizard, storing it's name
// and starting energy.
Wizard::Wizard(const std::string& name, int energy) {

}

// This function will try to use `amount` of energy.
// If the wizard has enough energy to decrease by
// amount and still be non-zero, then it will subtract
// from energy and return true. Otherwise, the energy
// should remain unchanged and it will return false.
bool Wizard::useEnergy(int amount) {

}

// This function should simply return the amount of energy
// the wizard has left.
int Wizard::getEnergy() const {

}

// This should simply return the name of the wizard.
std::string Wizard::getName() const {

}

// ==========================
// =   CLASS 2: SpellBook   =
// ==========================

// Add this spell to the spellbook.
void SpellBook::addSpell(const std::string& name, int cost) {

}

// Try to have the wizard cast all of the spells they can.
void SpellBook::castAll(Wizard& w) {

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
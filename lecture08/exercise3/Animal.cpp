#include "Animal.h"
#include <iostream>

// TODO: Implement the constructor
// Store the name parameter into the protected member variable
Animal::Animal(std::string name) {

}

// TODO: Implement the destructor
// It doesn't need to do anything — but it must be defined since it's virtual
Animal::~Animal() {

}

// TODO: Implement getName()
// Return the animal's name
std::string Animal::getName() const {

}

// TODO: Implement introduce()
// Print one line in this format:
//   Hi, I'm Buddy! Woof! ...and I run on all fours.
//
// Call this->speak() and this->move() — do NOT hardcode any sounds or movements.
// Virtual dispatch will automatically call the right derived class version at runtime.
void Animal::introduce() const {

}

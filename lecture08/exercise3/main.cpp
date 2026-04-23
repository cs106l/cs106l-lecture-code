#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"

int main() {

    // ---------------------------------------------------------------
    // PART 3: Build the zoo and run the loop
    // ---------------------------------------------------------------

    // TODO: Create an array of 4 Animal pointers.
    // Mix types — at least one Dog, one Cat, and one Bird.
    // Use 'new' to allocate each one on the heap.
    Animal* zoo[4] = {
        // new Dog("Buddy"),
        // new Cat("Whiskers"),
        // new Bird("Tweety"),
        // new Dog("Rex")
    };

    std::cout << "=== Welcome to the Virtual Zoo ===" << std::endl << std::endl;

    // TODO: Loop over the array and call introduce() on each animal.
    // Notice: even though we're using Animal* pointers, each animal
    // introduces itself differently. That's polymorphism.


    // ---------------------------------------------------------------
    // PART 4: Remove 'virtual' from speak() in Animal.h, recompile,
    // and observe what changes. Then write your explanation here:
    //
    // PART 4 ANSWER:
    //
    // ---------------------------------------------------------------


    // ---------------------------------------------------------------
    // PART 5: The destructor trap
    // ---------------------------------------------------------------

    // TODO: Add a loop here that deletes each animal in the zoo array.
    // Then go to Animal.h, remove 'virtual' from ~Animal(), recompile
    // with -Wall, and answer these questions as comments:
    //
    // Q1: What warning does the compiler give?
    //
    // Q2: What would go wrong if Dog had a 'new'd data member freed in ~Dog()?
    //
    // Q3: Why does 'virtual' on the destructor fix this?
    //


    return 0;
}

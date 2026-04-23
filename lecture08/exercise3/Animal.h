#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(std::string name);

    // Pure virtual — every derived class MUST override these
    virtual void speak()            const = 0;
    virtual void move()             const = 0;
    virtual std::string getType()   const = 0;

    // Virtual destructor — required whenever you delete through a base pointer
    virtual ~Animal();

    // Non-virtual — implemented once, calls speak() and move() internally
    std::string getName() const;
    void introduce()      const;
};

#endif

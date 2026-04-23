#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
public:
    Dog(std::string name);

    void speak()            const override;
    void move()             const override;
    std::string getType()   const override;

    // Dog-specific method — not on Animal
    void fetch() const;
};

#endif

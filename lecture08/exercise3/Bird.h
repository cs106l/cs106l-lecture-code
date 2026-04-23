#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird(std::string name);

    void speak()            const override;
    void move()             const override;
    std::string getType()   const override;

    // Bird-specific method — not on Animal
    void migrate() const;
};

#endif

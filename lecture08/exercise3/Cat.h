#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
    Cat(std::string name);

    void speak()            const override;
    void move()             const override;
    std::string getType()   const override;

    // Cat-specific method — not on Animal
    void purr() const;
};

#endif

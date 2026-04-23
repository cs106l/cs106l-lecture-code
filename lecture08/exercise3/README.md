# Exercise: The Virtual Zoo

Practice using `virtual` functions, pure virtual methods, polymorphism, and the virtual destructor.

---

## What you'll build

A small zoo simulator. You'll have a base class `Animal` and three derived classes: `Dog`, `Cat`, and `Bird`. A zoo loop will call the same methods on all of them through a base pointer — and you'll see each animal respond differently. That's polymorphism.

---

## Files you are given

| File | Status | What it is |
|------|--------|------------|
| `Animal.h` | Given — do not modify | Base class declaration |
| `Dog.h` | Given — do not modify | Dog class declaration |
| `Cat.h` | Given — do not modify | Cat class declaration |
| `Bird.h` | Given — do not modify | Bird class declaration |
| `Animal.cpp` | YOU write this | Base class implementation |
| `Dog.cpp` | YOU write this | Dog implementation |
| `Cat.cpp` | YOU write this | Cat implementation |
| `Bird.cpp` | YOU write this | Bird implementation |
| `main.cpp` | YOU write this | Zoo driver program |

---

## Part 1 — Understand the base class

Open `Animal.h` and read it carefully before writing anything.

Notice:
- `speak()`, `move()`, and `getType()` are **pure virtual** (`= 0`). This means:
  - `Animal` cannot be instantiated directly
  - Every derived class *must* override them or it won't compile
- `introduce()` is **not virtual**. It is implemented once in `Animal.cpp` and shared by all animals
- The destructor is `virtual` — you'll find out why this matters in Part 5

**Your task:** Create `Animal.cpp` and implement:
- The constructor (store the name)
- `getName()` (return the name)
- `introduce()` — print one line in this format:

```
Hi, I'm Buddy! Woof! ...and I run on all fours.
```

`introduce()` should call `this->speak()` and `this->move()` internally.
You do NOT need to know which animal is calling it — the virtual dispatch handles that.

---

## Part 2 — Implement the three derived classes

Create `Dog.cpp`, `Cat.cpp`, and `Bird.cpp`.

Each one must:
1. Call the base constructor (`Animal::Animal(name)`) in its initializer list
2. Override `speak()`, `move()`, and `getType()`
3. Implement its unique method

**Expected outputs:**

| Class | `speak()` | `move()` | `getType()` | Unique method |
|-------|-----------|----------|-------------|---------------|
| Dog | "Woof!" | "runs on all fours" | "Dog" | `fetch()` — prints "...fetches the ball!" |
| Cat | "Meow!" | "slinks gracefully" | "Cat" | `purr()` — prints "Purrrrr..." |
| Bird | "Tweet!" | "soars through the air" | "Bird" | `migrate()` — prints "Heading south for winter!" |

> Tip: Use the `override` keyword on each method you override. It's optional but will save you from hard-to-find bugs — the compiler will catch it if your signature doesn't actually match the base class.

---

## Part 3 — Write the zoo loop

Create `main.cpp`. Build an array of `Animal*` pointers with at least 4 animals (mix the types), loop over it, and call `introduce()` on each one.

**Starter structure:**

```cpp
#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"

int main() {
    Animal* zoo[4] = {
        new Dog("Buddy"),
        new Cat("Whiskers"),
        new Bird("Tweety"),
        new Dog("Rex")
    };

    std::cout << "=== Welcome to the Virtual Zoo ===" << std::endl << std::endl;

    for (int i = 0; i < 4; i++) {
        zoo[i]->introduce();
    }

    // TODO Part 5: add delete loop here

    return 0;
}
```

Compile and run. Every animal should introduce itself differently even though the loop only ever calls methods on an `Animal*` pointer.

**To compile:**
```bash
g++ -Wall -o zoo Animal.cpp Dog.cpp Cat.cpp Bird.cpp main.cpp
./zoo
```

---

## Part 4 — Break it on purpose

This is the most important part of the exercise.

1. Open `Animal.h`
2. Remove the `virtual` keyword from `speak()` (leave `= 0` off too — just make it a regular method returning an empty string)
3. Recompile and run

**What changed? Why?**

Write a comment in `main.cpp` above your zoo loop explaining what you observed and what caused it.

> Expected observation: all four animals now print the same thing (or nothing), because the compiler binds the call to `Animal::speak()` at compile time instead of resolving it at runtime through the vtable.

After you've written your comment, put `virtual` back before moving to Part 5.

---

## Part 5 — The destructor trap

1. Add a `delete` loop at the end of `main.cpp`:

```cpp
for (int i = 0; i < 4; i++) {
    delete zoo[i];
}
```

2. Now open `Animal.h` and remove `virtual` from the destructor (`~Animal()`).
3. Recompile with warnings:

```bash
g++ -Wall -o zoo Animal.cpp Dog.cpp Cat.cpp Bird.cpp main.cpp
```

**Questions to answer (write as comments in main.cpp):**

- What warning does the compiler give you?
- What would go wrong at runtime if `Dog` had its own dynamically allocated data (e.g., a `std::string* tricks` array allocated with `new` in Dog's constructor and freed in Dog's destructor)?
- Why does making the destructor `virtual` fix this?

> Hint: When you `delete` a `Dog*` cast as `Animal*`, the compiler needs to know which destructor to call. Without `virtual`, it always calls `~Animal()` and skips `~Dog()` entirely.

Put `virtual` back on the destructor when done.

---

## Bonus challenge

Add a fourth animal of your choice. Give it:
- A unique `speak()`, `move()`, and `getType()`
- One extra method not on any other animal
- At least two instances of it in the zoo array

---

## Concepts checklist

By the end of this exercise you should be able to explain:

- [ ] What a pure virtual function is and why a class with one cannot be instantiated
- [ ] What polymorphism means and how virtual dispatch enables it
- [ ] What the vtable is (look it up if you haven't heard of it)
- [ ] Why the `override` keyword is useful even though it's optional
- [ ] Why the destructor of a base class should almost always be `virtual`

/* File: main.cpp
 * Author: Preston Seay
 *
 * This file uses your bounded value template with ints.
 */
#include "bounded_value.h"
#include <iostream>

int main() {
    BoundedValue<int> health(120, 0, 100);

    std::cout << health.get() << std::endl; // expected: 100

    health.set(-10);
    std::cout << health.get() << std::endl; // expected: 0

    health.set(50);
    std::cout << health.get() << std::endl; // expected: 50

    health.adjust(60);
    std::cout << health.get() << std::endl; // expected: 100 (if implemented)

    return 0;
}
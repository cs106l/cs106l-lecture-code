/*
 * CS106L - Template Functions Practice
 * Problem 1: Fix the Template
 *
 * The following code has a bug. The program compiles but produces
 * incorrect / unpredictable results.
 *
 * Tasks:
 *   1. Run the code and observe the output.
 *   2. Explain WHY the output is wrong.
 *   3. Fix the code so it correctly returns "apple".
 *
 * Hint: What type does the compiler deduce for T?
 *       What does operator< actually do on that type?
 */

#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int main() {
    // BUG: this compiles but may not do what you expect!
    auto result = min("apple", "banana");
    std::cout << "min(\"apple\", \"banana\") = " << result << std::endl;

    // TODO: fix the call above so it correctly compares strings alphabetically.
    // Your fix should not change the template definition itself.

    return 0;
}

/*
 * CS106L - Template Functions Practice
 * Problem 2: Write a Template Function (3 minutes)
 *
 * Implement the templated `contains` function below so that it works
 * for any container with iterators.
 *
 * The function takes an iterator range [begin, end) and a value,
 * and returns true if the value is found, false otherwise.
 *
 * All four test cases in main() should print "true" or "false" correctly.
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>

// TODO: implement this function
// Hint: think about what template parameters you need.
//       What type is the iterator? What type is the value?
template <typename Iterator, typename TElem>
bool contains(Iterator begin, Iterator end, const TElem& value) {
    // YOUR CODE HERE
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::set<std::string> s = {"hello", "world", "cs106l"};

    std::cout << std::boolalpha;
    std::cout << "contains(v, 3):       " << contains(v.begin(), v.end(), 3)         << std::endl; // true
    std::cout << "contains(v, 99):      " << contains(v.begin(), v.end(), 99)        << std::endl; // false
    std::cout << "contains(s, hello):   " << contains(s.begin(), s.end(), std::string("hello"))   << std::endl; // true
    std::cout << "contains(s, goodbye): " << contains(s.begin(), s.end(), std::string("goodbye")) << std::endl; // false

    return 0;
}

#include <iostream>
#include <vector>

/**
 * EXERCISE: Implement binary search RECURSIVELY using vector iterators.
 * @param begin  Iterator to the start of the current search range
 * @param end    Iterator to the end of the current search range (exclusive)
 * @param value  The integer to search for
 * @return       true if found, false otherwise
 */
bool binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value) {
    // 1. Base Case: If the range is empty, the value isn't here.
    if (begin >= end) {
        return false;
    }

    // 2. Calculate the midpoint
    auto mid = begin + (std::distance(begin, end) / 2);

    // 3. Recursive Logic
    if (*mid == value) {
        return true;
    } 
    
    if (*mid > value) {
        // Search the left half: [begin, mid)
        // TODO: return binarySearchRecursive(...)
    } else {
        // Search the right half: [mid + 1, end)
        // TODO: return binarySearchRecursive(...)
    }

    return false; // Placeholder
}

int main() {
    std::vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int testValues[] = {23, 2, 91, 40}; // Found, Boundary (Start), Boundary (End), Not Found

    std::cout << "Recursive Iterator Binary Search Test:" << std::endl;
    for (int val : testValues) {
        std::cout << "Searching for " << val << ": " 
                  << (binarySearch(data.begin(), data.end(), val) ? "SUCCESS" : "FAILURE") 
                  << std::endl;
    }

    return 0;
}
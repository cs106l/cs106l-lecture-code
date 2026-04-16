/*

This file shows an ITERATIVE solution to the binary search problem.

*/
#include <iostream>
#include <vector>

/**
 * Performs a binary search using vector iterators.
 * @param begin  Iterator to the start of the range
 * @param end    Iterator to the end of the range (exclusive)
 * @param value  The integer to search for
 * @return       true if found, false otherwise
 */
bool binarySearch(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value) {
    while (begin < end) {
        // Calculate the distance and find the midpoint
        // (end - begin) gives the number of elements in the current range
        auto mid = begin + (end - begin) / 2;

        if (*mid == value) {
            return true; // Found the value
        } 
        else if (*mid < value) {
            // Value is in the right half, move begin past mid
            begin = mid + 1;
        } 
        else {
            // Value is in the left half, move end to mid
            end = mid;
        }
    }
    
    return false; // Range exhausted, value not found
}

int main() {
    // A sorted vector for testing
    std::vector<int> nums = {3, 9, 15, 21, 28, 34, 45, 56, 72, 89};

    // Test cases: elements that exist, don't exist, and boundary cases
    int tests[] = {21, 3, 89, 1, 50, 100};

    std::cout << "--- Iterator Binary Search Test ---" << std::endl;
    for (int t : tests) {
        bool result = binarySearch(nums.begin(), nums.end(), t);
        
        std::cout << "Searching for " << t << ": " 
                  << (result ? "FOUND" : "NOT FOUND") 
                  << std::endl;
    }

    return 0;
}
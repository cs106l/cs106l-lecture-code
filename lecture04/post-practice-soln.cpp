// ============================================================
//  streams_10min_SOLUTION.cpp
//  10 minute practice — SOLUTION FILE
// ============================================================
//
//  HOW TO COMPILE & RUN:
//    g++ -o streams_10min_solution streams_10min_SOLUTION.cpp
//    ./streams_10min_solution
//
// ============================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// ============================================================
//  EXERCISE 1 — cout
// ============================================================
void exercise1() {
    std::cout << "=== Student Grade Tracker ===" << "\n";
    std::cout << "Enter your details below." << "\n";
}


// ============================================================
//  EXERCISE 2 — cin
// ============================================================
void exercise2(std::string& name, int& grade) {
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your grade: ";
    std::cin >> grade;

    std::cout << "Student: " << name << "\n";
    std::cout << "Grade: " << grade << "\n";
}


// ============================================================
//  EXERCISE 3 — cerr
// ============================================================
bool exercise3(int grade) {
    if (grade < 0 || grade > 100) {
        std::cerr << "Error: invalid grade!\n";
        return false;
    }
    return true;
}


// ============================================================
//  EXERCISE 4 — ofstream
// ============================================================
void exercise4(const std::string& name, int grade) {
    std::ofstream out("grades.txt");

    if (!out.is_open()) {
        std::cerr << "Error: could not open file\n";
        return;
    }

    out << name << " " << grade << "\n";
    std::cout << "Saved to grades.txt!\n";
}


// ============================================================
//  EXERCISE 5 — ifstream
// ============================================================
void exercise5() {
    std::ifstream in("grades.txt");

    if (!in.is_open()) {
        std::cerr << "Error: could not open file\n";
        return;
    }

    std::string name;
    int grade;
    while (in >> name >> grade) {
        std::cout << "Name: " << name << "  |  Grade: " << grade << "\n";
    }
}


// ============================================================
//  EXERCISE 6 — putting it all together
// ============================================================
void exercise6() {
    std::cout << "\n=== Tracking 3 Students ===\n";

    for (int i = 0; i < 3; i++) {
        std::string name;
        int grade;

        // get student info
        std::cout << "\nEnter name for student " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter grade: ";
        std::cin >> grade;

        // validate grade
        if (!exercise3(grade)) {
            std::cout << "Skipping " << name << " due to invalid grade.\n";
            continue;   // skip saving this student
        }

        // append to file
        std::ofstream out("grades.txt", std::ios::app);
        if (!out.is_open()) {
            std::cerr << "Error: could not open file\n";
            return;
        }
        out << name << " " << grade << "\n";
        std::cout << "Saved " << name << "!\n";
    }

    // read everyone back
    std::cout << "\n=== All Students ===\n";
    exercise5();
}


// ============================================================
//  MAIN
// ============================================================
int main() {
    // Exercise 1 — welcome message
    exercise1();
    std::cout << "\n";

    // Exercise 2 — get student info
    std::string name;
    int grade;
    exercise2(name, grade);
    std::cout << "\n";

    // Exercise 3 — validate grade
    if (!exercise3(grade)) {
        std::cerr << "Please restart and enter a valid grade.\n";
        return 1;
    }
    std::cout << "\n";

    // Exercise 4 — save to file
    exercise4(name, grade);
    std::cout << "\n";

    // Exercise 5 — read back from file
    exercise5();
    std::cout << "\n";

    // Exercise 6 — full tracker
    exercise6();

    return 0;
}

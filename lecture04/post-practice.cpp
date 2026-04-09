#include <iostream>
#include <fstream>
#include <string>

// ============================================================
//  EXERCISE 1 — cout 
//
//  Task: Print a welcome message to the console:
//          "=== Student Grade Tracker ==="
//          "Enter your details below."
// ============================================================
void exercise1() {
    // YOUR CODE HERE
}


// ============================================================
//  EXERCISE 2 — cin 
//
//  Task: Ask the student for their name and their grade (int).
//        Then print:
//          "Student: [name]"
//          "Grade: [grade]"
//
//  Note: assume the name is one word for now
// ============================================================
void exercise2(std::string& name, int& grade) {
    // YOUR CODE HERE
    // note: we pass name and grade by reference so later
    // exercises can use them!
}


// ============================================================
//  EXERCISE 3 — cerr 
//
//  Task: Validate the grade from exercise 2.
//        If the grade is less than 0 or greater than 100:
//          - print "Error: invalid grade!" to cerr
//          - return false
//        Otherwise return true
// ============================================================
bool exercise3(int grade) {
    // YOUR CODE HERE
    return true;
}


// ============================================================
//  EXERCISE 4 — ofstream 
//
//  Task: Save the student's name and grade to "grades.txt"
//        in the format:
//          [name] [grade]
//
//  Requirements:
//    - check the file opened successfully
//    - if it fails, print "Error: could not open file" to cerr
//    - print "Saved to grades.txt!" to cout on success
// ============================================================
void exercise4(const std::string& name, int grade) {
    // YOUR CODE HERE
}


// ============================================================
//  EXERCISE 5 — ifstream  
//
//  Task: Read back "grades.txt" and print each entry as:
//          "Name: [name]  |  Grade: [grade]"
//
//  Requirements:
//    - check the file opened successfully
//    - use a while loop to read until end of file
// ============================================================
void exercise5() {
    // YOUR CODE HERE
}


// ============================================================
//  EXERCISE 6 — putting it all together  (~2 mins)
//
//  Task: Extend the tracker to handle 3 students in a loop.
//        Follow the steps below carefully!
// ============================================================
void exercise6() {
    std::cout << "\n=== Tracking 3 Students ===\n";

    for (int i = 0; i < 3; i++) {

        // ---------------------------------------------------------
        // STEP 1: declare a string called name and an int called grade
        // ---------------------------------------------------------
        // YOUR CODE HERE


        // ---------------------------------------------------------
        // STEP 2: prompt the user and read in name and grade with cin
        //   print "Enter name for student [i+1]: " before reading name
        //   print "Enter grade: " before reading grade
        // ---------------------------------------------------------
        // YOUR CODE HERE


        // ---------------------------------------------------------
        // STEP 3: call exercise3(grade) to validate the grade
        //   if it returns false:
        //     - print "Skipping [name] due to invalid grade."
        //     - use continue to skip to the next student
        // ---------------------------------------------------------
        // YOUR CODE HERE


        // ---------------------------------------------------------
        // STEP 4: open "grades.txt" with ofstream using std::ios::app
        //   check it opened successfully — if not, print error and return
        //   write name and grade to the file in the format: [name] [grade]
        //   print "Saved [name]!" to cout
        // ---------------------------------------------------------
        // YOUR CODE HERE

    }

    // ---------------------------------------------------------
    // STEP 5: print "\n=== All Students ===" then call exercise5()
    //         to read back and print everyone in the file
    // ---------------------------------------------------------
    // YOUR CODE HERE

}


// ============================================================
//  MAIN — comment out exercises you haven't reached yet
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

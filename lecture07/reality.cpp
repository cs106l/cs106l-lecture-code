/* File: reality.cpp
 * Author: Preston Seay
 *
 * This file demonstrates how code works without the virtual keyword,
 * showing slicing (a form of narrowing conversion).
 * 
 * In the real world, you'd want to define these in .h files, but
 * for this example, I wanted them all to be in one file
 * so you can easily see them.
 */

#include <iostream>
using namespace std;

// Define three types: A, B, and C such that A has int a,
// and B has ints a and b, and C has ints a, b, and c.
struct A {
    int a;
    void print() { cout << "A: " << a << endl; }
};
struct B : A { // Structs inherit public by default.
    int b;
    void print() { cout << "B: " << a << ", " << b << endl; }
};
class C : B { // Classes inherit private by default.
    int c; // Fields default to private too.
public:
    C(int c): c(c) {
        a = c - 2;
        b = c - 1;
    }
    void print() { cout << "C: " << a << ", " << b << ", " << c << endl; }
};

int main() {
    //// Uniform Initialization -- works as usual :) ////
    cout << endl << "-- Uniform Init" << endl;

    B b {1, 2}; // set a = 1, b = 2
    b.print();  // prints B: 1, 2
    C c {1};
    c.print();  // prints C: -1, 0, 1

    //// Slicing... we can turn B into an A. ////
    cout << endl << "-- Slicing" << endl;

    A a {3};
    a.print();       // prints A: 3
    ((A)b).print();  // prints A: 1

    A aArray[3];
    aArray[0] = a;
    aArray[1] = b;
    //aArray[2] = c; This would not be allowed, since B & A are inaccessible.
    for (int i = 0; i < 2; i++) {
        aArray[i].print(); // Prints A: ...
    }

    //// Sizing... ////
    cout << endl << "-- Sizing" << endl;

    // [4 bytes of a]
    cout << "A is " << sizeof(A) << " bytes" << endl;
    // [4 bytes of a, 4 bytes of b]
    cout << "B is " << sizeof(B) << " bytes" << endl;
    // [4 bytes of a, 4 bytes of b, 4 bytes of c]
    cout << "C is " << sizeof(C) << " bytes" << endl;

    //// Access to private variables... ////
    cout << endl << "-- Memory" << endl;

    cout << "C before:" << endl;
    c.print();
    int* cAddress = (int*) &c;
    cAddress[0] = 10;
    cAddress[1] = 6;
    cout << "C after:" << endl;
    c.print();

    return 0;
}
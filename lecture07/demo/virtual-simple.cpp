/* File: virtual-simple.cpp
 * Author: Preston Seay
 * 
 * This file demonstrates the simple properties of virtual.
 * It will take more space and determine at *runtime* what
 * function to call or base it has.
 */

#include <iostream>
using namespace std;

// Inheritance without virtual.
struct A {
    long long a;
    void f() { cout << "A" << a << endl; }
};
struct B : A {
    long long b;
    void f() { cout << "B" << b << endl; }
};

// Inheritance with virtual.
struct C {
    long long c;
    virtual void f() { cout << "C" << c << endl; }

    C(long long c) : c(c) {}
};
struct D : C {
    long long d;
    void f() override { cout << "D" << d << endl; }

    D(long long c, long long d) : C(c), d(d) {}
};

int main() {
    cout << "-- Non-Virtual --" << endl;

    // Without virtual, the function to run is determined at compile time :)
    A* bInstance = new B{1, 2};
    bInstance->f();         // prints A1
    (*((B*)bInstance)).f(); // prints B2

    // At compile time, the function f is determined based upon the type (A).
    ((A)*bInstance).f();    // prints A1

    cout << "-- Virtual --" << endl;

    // With virtual, it does not refer to the type (e.g., C*); it looks up
    // the function to run in the vtable.
    C* dInstance = new D{3, 4};
    dInstance->f();         // prints D4
    (*((D*)dInstance)).f(); // prints D4

    // When we slice an object, the vtable pointer changes as it has to
    // fit into a c object, which a d object does not :(
    ((C)*dInstance).f();    // prints C3

    cout << "-- Memory --" << endl;

    // We can see that the pointer to the vtable makes the objects take more
    // space so that it knows what type of object it is.
    cout << "sizeOf(A) == " << sizeof(A) << " && sizeOf(B) == " << sizeof(B) << endl;
    cout << "sizeOf(C) == " << sizeof(C) << " && sizeOf(D) == " << sizeof(D) << endl;
}
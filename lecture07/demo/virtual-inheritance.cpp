/* File: virtual-inheritance.cpp
 * Author: Preston Seay
 * 
 * This file demonstrates how virtual inheritance works.
 */
#include <iostream>
using namespace std;

// Non-virtual inheritance (duplication)
struct A { int x; A(int x) : x(x) {} };

struct B : A { B() : A(1) {} };
struct C : A { C() : A(2) {} };

// Note: D now contains two A subobjects.
struct D : B, C {};

// Virtual inheritance (sharing)
struct VA { int x; VA(int x) : x(x) {} };

struct VB : virtual VA { VB() : VA(1) {} };
struct VC : virtual VA { VC() : VA(2) {} };

// Note: VD contains one VA subobject.
struct VD : VB, VC {
    VD() : VA(3), VB(), VC() {}
};



int main() {
    D d;

    // Two independent A's:
    cout << d.B::x << " " << d.C::x << endl; // 1 2
    // cout << d.x; // This would not compile since it would be ambiguous.

    VD vd;

    // One shared VA:
    cout << vd.x << endl; // 3
    cout << vd.VB::x << " " << vd.VC::x << endl; // 3 3

    cout << sizeof(A) << " <= " << sizeof(B) << " <= " << sizeof(D) << endl;
    cout << sizeof(VA) << " <= " << sizeof(VB) << " <= " << sizeof(VD) << endl;
}
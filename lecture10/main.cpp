#include <iostream>
#include <ios>

#include "Vector.h"

int main() {
  /* Call default vector constructor */
  Vector<int> vector;
  Vector<double> doubleVector;
  Vector<std::string> sv;

  /* Push 106 onto the end of the vector 5 times */
  for (int i = 0; i < 5; i++) {
    vector.push_back(106);
  }

  /* Modify vector using both at and subscript operator */
  vector.at(0) = 100;
  vector[1] = 200;
  vector[2] = 300;

  /* Print contents of vector using for-each loop */
  std::cout << "Size of Vector: " << vector.size() << "\n";
  std::cout << "Vector is Empty: " << std::boolalpha << vector.empty() << "\n";
  std::cout << "Contents of vector: ";
  for (const auto& element : vector) {
    std::cout << element << " ";
  }
  std::cout << "\n";

  return 0;
}
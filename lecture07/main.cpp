#include <iostream>
#include "StudentID.h"
#include "IntVector.h"

void createStudentID() {
  StudentID sid{"Jacob Roberts-Baca", "6504417", 2025};
  std::cout << "Name: " << sid.getName() << std::endl;
  std::cout << "Sunet: " << sid.getSunet() << std::endl;
  std::cout << "ID Number: " << sid.getIdNumber() << std::endl;
}

int main() {
  createStudentID();
  return 0;
}

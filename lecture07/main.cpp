#include <iostream>
#include <string>
#include "include/SectionLeader.h"
#include "include/StudentID.h"

void createStudentID() {
  StudentID sid{"Jacob Roberts-Baca", "6504417", 2025};
  std::cout << "Name: " << sid.getName() << std::endl;
  std::cout << "Sunet: " << sid.getSunet() << std::endl;
  std::cout << "ID Number: " << sid.getIdNumber() << std::endl;
}

void createSectionLeader() {
  SectionLeader sl{"Jacob Roberts-Baca", "6504417", "Computer Science", "Keith Schwarz", 2025, "01", "CS106B", 25};
  // std::cout << "Section Leader created: " << sl.getName() << ", for course " << sl.getCourse() << std::endl;
}

int main() {
  int choice;

  std::cout << "Choose an option:\n";
  std::cout << "1. Create Student ID\n";
  std::cout << "2. Create Section Leader\n";
  std::cout << "Enter your choice (1 or 2): ";
  std::cin >> choice;

  std::cout << "################################################################################\n";

  if (choice == 1) {
    createStudentID();
  } else if (choice == 2) {
    createSectionLeader();
  } else {
    std::cout << "Invalid choice, please enter 1 or 2.\n";
  }

  return 0;
}

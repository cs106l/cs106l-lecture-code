#include "../include/Employee.h"
#include <iostream>

Employee::Employee(const std::string& name, double salary) : Person(name), salary(salary) {
    std::cout << "Employee constructor" << std::endl;
}


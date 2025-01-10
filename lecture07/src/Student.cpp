#include "../include/Student.h"
#include <cstdint>
#include <iostream>

Student::Student(const std::string& name, const std::string& idNumber, const std::string& major, const std::string& advisor, uint16_t year) : Person(name), idNumber(idNumber), major(major), advisor(advisor), year(year) {
    std::cout << "Student constructor" << std::endl;
}

std::string Student::getIdNumber() const {
    return idNumber;
}

uint16_t Student::getYear() const {
    return year;
}

void Student::setYear(uint16_t year) {
    this->year = year;
}

std::string Student::getMajor() const {
    return major;
}

void Student::setMajor(const std::string& major) {
    this->major = major;
}

std::string Student::getAdvisor() const {
    return advisor;
}

void Student::setAdvisor(const std::string& advisor) {
    this->advisor = advisor;
}

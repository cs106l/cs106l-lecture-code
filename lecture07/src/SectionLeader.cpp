#include "../include/SectionLeader.h"
#include <iostream>

#ifdef VIRTUAL_INHERITANCE
SectionLeader::SectionLeader(const std::string& name, const std::string& idNumber, const std::string& major, const std::string& advisor, uint16_t year, const std::string& section, const std::string& course, double salary) : Person(name), Student(name, idNumber, major, advisor, year), Employee(name, salary), section(section), course(course) {
#else
SectionLeader::SectionLeader(const std::string& name, const std::string& idNumber, const std::string& major, const std::string& advisor, uint16_t year, const std::string& section, const std::string& course, double salary) : Student(name, idNumber, major, advisor, year), Employee(name, salary), section(section), course(course) {
#endif
    std::cout << "Section Leader constructor" << std::endl;
}

std::string SectionLeader::getSection() const {
    return section;
}

std::string SectionLeader::getCourse() const {
    return course;
}

void SectionLeader::addStudent(const std::string& student) {
    students.push_back(student);
}

void SectionLeader::removeStudent(const std::string& student) {
    // erase-remove idiom
    students.erase(std::remove(students.begin(), students.end(), student), students.end());
}

std::vector<std::string> SectionLeader::getStudents() const {
    return students;
}

std::string SectionLeader::getRole() const {
    return "Section Leader";
}

double SectionLeader::getSalary() const {
    return salary;
}

void SectionLeader::setSalary(double salary) {
    this->salary = salary;
}

SectionLeader::~SectionLeader() = default;

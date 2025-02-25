#include <iostream>
#include "StudentID.h"

#define LIST_INITIALIZATION 0

/// @brief Default constructor for the StudentID class
StudentID::StudentID() {
    name = "John Appleseed";
    sunet = "jappleseed";
    idNumber = 00000001;
}

/// @brief Destructor for the StudentID class
StudentID::~StudentID() {
    std::cout << "Destructor is called" << std::endl;
}

#if LIST_INITIALIZATION
StudentID::StudentID(std::string name, std::string sunet, int idNumber) : name{name}, sunet{sunet}, idNumber{idNumber} {}
#else

/// @brief Parameterized constructor for the StudentID class
/// @param name 
/// @param sunet 
/// @param idNumber 
StudentID::StudentID(std::string name, std::string sunet, int idNumber) {
    this->name = name;
    this->sunet = sunet;
    if (idNumber >= 0) {
        this->idNumber = idNumber;
    } else {
        this->idNumber = 0;
    }
}

/// @brief Getter function for the name member variable in a StudentID
/// @return The StudentID object's name 
std::string StudentID::getName() {
    return name;
}

/// @brief Getter function for the sunet member variable in a StudentID
/// @return The StudentID object's sunet
std::string StudentID::getSunet() {
    return sunet;
}

/// @brief Getter function for the idNumber member variable in a StudentID
/// @return The StudentID object's idNumber
int StudentID::getIdNumber() {
    return idNumber;
}

/// @brief Setter function for the name member variable in a StudentID
/// @param name 
void StudentID::setName(std::string name) {
    this->name = name; 
}

/// @brief Setter function for the sunet member variable in a StudentID
/// @param sunet
void StudentID::setSunet(std::string sunet) {
    this->sunet = sunet; 
}

/// @brief Setter function for the idNumber member variable in a StudentID
/// @param id
void StudentID::setIdNumber(int id) {
    this->idNumber = id; 
}
#endif
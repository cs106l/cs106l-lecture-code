#include "../include/StudentID.h"

// List initialization constructor
// StudentID::StudentID(std::string name, std::string sunet, int idNumber) : name(name), sunet(sunet), idNumber(idNumber) {}

// Default Constructor
StudentID::StudentID() {
    name = "John Appleseed";
    sunet = "jappleseed";
    idNumber = 00000001;
}

StudentID::StudentID(std::string name, std::string sunet, int idNumber) {
    this->name = name;
    this->sunet = sunet;
    if (idNumber >= 0) {
        this->idNumber = idNumber;
    } else {
        this->idNumber = 0;
    }
}

std::string StudentID::getName() {
    return name;
}

std::string StudentID::getSunet() {
    return sunet;
}

int StudentID::getIdNumber() {
    return idNumber;
}

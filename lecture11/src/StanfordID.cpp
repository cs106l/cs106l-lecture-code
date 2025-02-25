#include "../include/StanfordID.h"

// List initialization constructor
// StanfordID::StanfordID(std::string name, std::string sunet, int idNumber) : name(name), sunet(sunet), idNumber(idNumber) {}

// Default Constructor
StanfordID::StanfordID() {
    name = "John Appleseed";
    sunet = "jappleseed";
    idNumber = 00000001;
}

StanfordID::StanfordID(std::string name, std::string sunet, int idNumber) {
    this->name = name;
    this->sunet = sunet;
    if (idNumber >= 0) {
        this->idNumber = idNumber;
    } else {
        this->idNumber = 0;
    }
}

std::string StanfordID::getName() const {
    return name;
}

std::string StanfordID::getSunet() const {
    return sunet;
}

int StanfordID::getIdNumber() const {
    return idNumber;
}

/* Member functions */
#ifdef MEMBER_WISE
bool StanfordID::operator<(const StanfordID& other) const {
    return idNumber < other.idNumber;
}
#endif // MEMBER_WISE

bool StanfordID::operator==(const StanfordID& other) const {
    return idNumber == other.idNumber;
}

bool StanfordID::operator!=(const StanfordID& other) const {
    return !(idNumber == other.idNumber);
}


void StanfordID::operator@(const StanfordID& other) const {
    std::cout << "It works!" << std::endl;
}
/* End member operators */


#ifndef MEMBER_WISE
// non-member function
bool operator<(const StanfordID& lhs, const StanfordID& rhs){
    return lhs.getIdNumber() < rhs.getIdNumber();
}
#endif // MEMBER_WISE
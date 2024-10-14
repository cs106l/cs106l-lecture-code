#include <string>

#ifndef PERSON_H
#define PERSON_H
#include "Person.h"
#endif

#ifdef VIRTUAL_INHERITANCE
class Student : virtual public Person {
#else
class Student : public Person {
#endif
  protected:
    std::string idNumber;
    std::string major;
    std::string advisor;
    uint16_t year;

  public:
    Student(const std::string& name, const std::string& idNumber, const std::string& major, const std::string& advisor, uint16_t year);
    std::string getIdNumber() const;
    std::string getMajor() const;
    uint16_t getYear() const;
    void setYear(uint16_t year);
    // major is mutable
    void setMajor(const std::string& major);
    std::string getAdvisor() const;
    // advisor is mutable
    void setAdvisor(const std::string& advisor);
    ~Student() = default;
};
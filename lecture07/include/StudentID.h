#include <string>
class StudentID {
protected:
    std::string name;
    std::string sunet;
    int idNumber;
public:
    StudentID(std::string name, std::string sunet, int idNumber);
    // default constructor
    StudentID();
    std::string getName();
    std::string getSunet();
    int getIdNumber();
};
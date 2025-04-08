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
    ~StudentID();

    // Getter functions
    std::string getName();
    std::string getSunet();
    int getIdNumber();

    // Setter functions
    void setName(std::string name);
    void setSunet(std::string sunet);
    void setIdNumber(int idNumber);
};
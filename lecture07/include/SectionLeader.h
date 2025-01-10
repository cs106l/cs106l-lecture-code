#include <string>
#include <vector>
#include "Employee.h"

class SectionLeader: public Student, public Employee {
    protected:
        std::string section;
        std::string course;
        std::vector<std::string> students;
    public:
        SectionLeader(const std::string& name, const std::string& idNumber, const std::string& major, const std::string& advisor, uint16_t year, const std::string& section, const std::string& course, double salary);
        std::string getSection() const;
        std::string getCourse() const;
        void addStudent(const std::string& student);
        void removeStudent(const std::string& student);
        std::vector<std::string> getStudents() const;
        std::string getRole() const override;
        double getSalary() const override;
        void setSalary(double salary) override;
        ~SectionLeader();
};
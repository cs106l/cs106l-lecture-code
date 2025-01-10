#include <string>
#include "Student.h"

#ifdef VIRTUAL_INHERITANCE
class Employee : virtual public Person {
#else
class Employee : public Person {
#endif
    protected:
        double salary;

    public:
        Employee(const std::string& name, double salary);
        virtual std::string getRole() const = 0;
        virtual double getSalary() const = 0;
        virtual void setSalary(double salary) = 0;
        // destructor
        virtual ~Employee() = default;
};
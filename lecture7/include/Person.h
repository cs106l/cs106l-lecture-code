#include <string>

class Person {
  protected:
    std::string name;
  public:
    // list initialization constructor
    Person(const std::string& name);
    std::string getName() const;
};

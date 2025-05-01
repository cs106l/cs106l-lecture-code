#include <string>
#include <iostream>
class StanfordID {
private:
    std::string name;
    std::string sunet;
    int idNumber;
public:
    StanfordID(std::string name, std::string sunet, int idNumber);
    // default constructor
    StanfordID();
    std::string getName() const;
    std::string getSunet() const;
    int getIdNumber() const;
#ifdef MEMBER_WISE
    bool operator<(const StanfordID& other) const;
#endif // MEMBER_WISE
    bool operator==(const StanfordID& other) const;
    bool operator!=(const StanfordID& other) const;
    void operator::(const StanfordID& other) const;
    friend bool operator<(const StanfordID& lhs, const StanfordID& rhs);
};
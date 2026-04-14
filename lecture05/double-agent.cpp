#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

// TODO: Implement this function
// Find all employees that appear in more than one department.
std::set<std::string> findDoubleAgents(std::map<std::string, std::set<std::string>> departments) {
    std::set<std::string> seen;
    std::set<std::string> doubleAgents;

    // Your code here
    
    return doubleAgents;
}

int main() {
    std::map<std::string, std::set<std::string>> company = {
        {"Sales", {"Jim", "Dwight", "Phyllis"}},
        {"Accounting", {"Angela", "Oscar", "Kevin"}},
        {"Pranks", {"Jim", "Pam"}}
    };

    std::set<std::string> multiTaskers = findDoubleAgents(company);

    std::cout << "Double Agents: ";
    for (auto name : multiTaskers) std::cout << name << " "; // Should print Jim
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

std::set<std::string> findDoubleAgents(std::map<std::string, std::set<std::string>> departments) {
    std::set<std::string> seen, doubleAgents;
    for (auto const& [dept, employees] : departments) {
        for (const std::string& name : employees) {
            if (!seen.insert(name).second) {
                doubleAgents.insert(name);
            }
        }
    }
    
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
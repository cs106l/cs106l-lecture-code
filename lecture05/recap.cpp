#include <iostream>
#include <sstream>
#include <string>
int main() {
    std::stringstream ss;
    ss << 3.14f << ' ' << "hello"; // use as ostream

    float pi; std::string hi;
    ss >> pi >> hi; // use as istream

    std::cout << pi << '\n' << hi << std::endl;
}
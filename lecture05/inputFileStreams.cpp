#include <fstream>
#include <iostream>

int main() {
  std::ifstream ifs("input.txt");
  if (ifs.is_open()) {
    std::string line;
    std::getline(ifs, line);
    std::cout << "Read from the file: " << line << '\n';
  }
  if (ifs.is_open()) {
    std::string lineTwo;
    std::getline(ifs, lineTwo);
    std::cout << "Read from the file: " << lineTwo << '\n';
  }
  return 0;
}

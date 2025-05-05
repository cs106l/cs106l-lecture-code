#include <string>
#include <iostream>
#include <limits>

void cinGetlineBug() {
  double pi;
  double tao;
  std::string name;
  std::cin >> pi;
  // std::cin >> name;
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // discard leftover newline
  std::getline(std::cin, name);
  std::cin >> tao;
  std::cout << "my name is : " << name << " tao is : " << tao
            << " pi is : " << pi << '\n';
}

int main() {
    cinGetlineBug();
    return 0;
}
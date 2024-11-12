/*
 * Credit to Sarah McCarthy '23 for this example
 */

#include <iostream>
#include <optional>

std::optional<int> divide(int numerator, int denominator) {
  if (denominator != 0) {
    return numerator / denominator;
  } else {
    return std::nullopt;
  }
}

int main() {
  int a = 10;
  int b = 2;

  std::optional<int> result = divide(a, b);

  if (result) {
    std::cout << "Result: " << result.value() << std::endl;
  } else {
    std::cout << "Division by zero occurred." << std::endl;
  }

  result = divide(10, 0);

  if (result) {
    std::cout << "Result: " << result.value() << std::endl;
  } else {
    std::cout << "Division by zero occurred." << std::endl;
  }

  return 0;
}
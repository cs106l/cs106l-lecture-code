#include <iostream>
#include <utility>

#include <cmath>

using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>; 

/**
 * Solves the equation ax^2 + bx + c = 0
 * @param a The coefficient of x^2
 * @param b The coefficient of x
 * @param c The constant term
 * @return A pair. The first element (bool) indicates if the equation has a solution.
 *                 The second element is a pair of the roots if they exist.
 */
Solution solveQuadratic(double a, double b, double c)
{
  // Your code here...
  double discrim = b * b - 4 * a * c;
  if (discrim < 0) return { false, { 106, 106 }};

  double root = sqrt(discrim);
  return { true, { (-b - root) / (2 * a), (-b + root) / (2 * a) }};
}

int main() {
  // Get the values for a, b, and c from the user
  double a, b, c;
  std::cout << "a: "; std::cin >> a;
  std::cout << "b: "; std::cin >> b;
  std::cout << "c: "; std::cin >> c;

  // Solve the quadratic equation, using our quadratic function above
  auto result = solveQuadratic(a, b, c);
  if (result.first) {
    auto solutions = result.second;
    std::cout << "Solutions: " << solutions.first << ", " << solutions.second << std::endl;
  } else {
    std::cout << "No solutions" << std::endl;
  }

  return 0;
}
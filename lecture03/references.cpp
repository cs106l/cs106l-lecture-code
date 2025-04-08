#include <iostream>
#include <math.h>

#define WITH_REF 1

/*
 * This is called a preprocessor macro, in the compilation step
 * the preprocessor, will decide which one of the function
 * signatures to keep depending on whether or not the variable
 * 'WITH_REF' is truthy. 
 */
#if WITH_REF
void squareN(int& n) 
#else
void squareN(int n)
#endif
{
	n = std::pow(n, 2);
}


int main() {
	int num = 5;
	std::cout << "(1) num is: " << num << std::endl;
	squareN(5);
	std::cout << "(2) num is " << num << std::endl;
	return 0;
}


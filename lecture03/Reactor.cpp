#include <iostream>


/*
 * I don't know whether or not Reactor code is written in C++,
 * but I wouldn't be surprised. Oftentimes these systems are controlled
 * using industrial PLCs, which may run C++ code. The reason I'm telling
 * you this is because oftentimes these narrowing conversions
 * seem trivial, but they're actually quite consequential :)
 */
class Reactor {
public:
	// this is called a Constructor, more on this later in the course
	Reactor(double temperature): temperature(temperature) {}

	void checkCool() {
		if (temperature > 100.0) {
			std::cout << "Emergency cooling!" << std::endl;
		}
		else {
			std::cout << "Temperature is normal. No emergency cooling required" << std::endl;
		}
	}


private:
	double temperature;
};


int main () {
	// narrowing conversion, saving 100.8 into an integer, see type on line 32
	int criticalTemperature(100.8);
	Reactor reactor(criticalTemperature);
	reactor.checkCool();
	return 0;
}

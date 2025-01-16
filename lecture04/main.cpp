#include <fstream>
#include <iostream>

int main() {
	/// associating file on construction
	std::ofstream ofs("hello.txt");
	if (ofs.is_open()) {
		ofs << "Hello CS106L!" << '\n';
    }
    ofs.close();
    ofs << "this will not get written";

    ofs.open("hello.txt");
    ofs << "this will though! It's open again";
        return 0;
}

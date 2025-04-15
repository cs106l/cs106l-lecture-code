#include <string>
#include <iostream>
#include <sstream>

void foo() {
    /// partial Bjarne Quote
    std::string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot"; 
    
    /// create a stringstream
    std::stringstream ss(initial_quote);
    
    /// data destinations
    std::string first;
    std::string last;
    std::string language, extracted_quote;
        
    ss >> first >> last >> language;
    std::cout << first << " " << last << " said this: "<< language << " " << extracted_quote << std::endl;
}

int main() {
    foo();
    return 0;
}



    
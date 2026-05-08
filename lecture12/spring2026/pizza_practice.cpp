#include <iostream>
#include <string>

class PizzaOrder {
public:
    PizzaOrder(std::string customer, std::string topping, int slices);

    std::string getCustomer() const;
    std::string getTopping()  const;
    int         getSlices()   const;

    PizzaOrder& operator+=(int slices);
    bool operator==(const PizzaOrder& other) const;

    friend std::ostream& operator<<(std::ostream& os, const PizzaOrder& order);

private:
    std::string customer;
    std::string topping;
    int slices;
};

bool operator<(const PizzaOrder& lhs, const PizzaOrder& rhs);
bool operator>(const PizzaOrder& lhs, const PizzaOrder& rhs);

// Constructor and getters
PizzaOrder::PizzaOrder(std::string customer, std::string topping, int slices)
    : customer(customer), topping(topping), slices(slices) {}

std::string PizzaOrder::getCustomer() const { return customer; }
std::string PizzaOrder::getTopping()  const { return topping; }
int         PizzaOrder::getSlices()   const { return slices; }

// MEMBER: +=
PizzaOrder& PizzaOrder::operator+=(int slices) {
    this->slices += slices;
    return *this;
}

// MEMBER: ==
bool PizzaOrder::operator==(const PizzaOrder& other) const {
    return customer == other.customer && topping == other.topping;
}

// NON-MEMBER: 
bool operator<(const PizzaOrder& lhs, const PizzaOrder& rhs) {
    return lhs.getSlices() < rhs.getSlices();
}

// NON-MEMBER: > (reusing <)
bool operator>(const PizzaOrder& lhs, const PizzaOrder& rhs) {
    return rhs < lhs;
}

// NON-MEMBER: 
std::ostream& operator<<(std::ostream& os, const PizzaOrder& order) {
    os << order.customer << ": " << order.slices << ", " << order.topping;
    return os;
}

int main() {
    PizzaOrder alice("Alice", "pepperoni", 3);
    PizzaOrder bob("Bob",     "cheese",    8);
    PizzaOrder alice2("Alice", "pepperoni", 6);

    alice += 4;
    std::cout << alice.getCustomer() << " slices: " << alice.getSlices() << "\n";  // should be 7

    std::cout << (alice == alice2 ? "same order" : "different order") << "\n";  // same order

    std::cout << (alice < bob ? "alice ordered less" : "alice did not order less") << "\n";  // alice ordered less

    std::cout << (bob > alice ? "bob is so hungry" : "bob is not that hungry") << "\n";  // bob is so hungry

    std::cout << alice << "\n";  // Alice: 7x pepperoni
    std::cout << bob   << "\n";  // Bob: 8x cheese

    return 0;
}

cout << rachel

template <int LOW, int HIGH>
class BoundedValue {
    int value;
public:
    BoundedValue(int v) {
        if (v < LOW) v = LOW;
        if (v > HIGH) v = HIGH;
        value = v;
    }

    int get() const {
        return value;
    }

    void set(int v) {
        if (v < LOW) v = LOW;
        if (v > HIGH) v = HIGH;
        value = v;
    }
};

#include <iostream>

int main() {
    BoundedValue<0, 100> health {120};
    std::cout << "120 becomes " << health.get() << std::endl;
    health.set(50);
    std::cout << "50 becomes " << health.get() << std::endl;
    health.set(0);
    std::cout << "0 becomes " << health.get() << std::endl;


    BoundedValue<0, 5> rating {10};
    std::cout << "10 star rating becomes a " << rating.get() << " rating" << std::endl;
}
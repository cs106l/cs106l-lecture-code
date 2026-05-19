// MyOptional Solution
// Simplified optional type implementation.

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <type_traits>

template <typename T>
class MyOptional {
private:
    bool _hasValue;
    T _value;

public:
    MyOptional() : _hasValue(false), _value() {}

    MyOptional(const T& value) : _hasValue(true), _value(value) {}

    MyOptional(T&& value) : _hasValue(true), _value(std::move(value)) {}

    bool hasValue() const {
        return _hasValue;
    }

    T& value() {
        if (!_hasValue) {
            throw std::runtime_error("MyOptional: no value");
        }
        return _value;
    }

    const T& value() const {
        if (!_hasValue) {
            throw std::runtime_error("MyOptional: no value");
        }
        return _value;
    }

    T value_or(T&& fallback) const {
        if (_hasValue) {
            return _value;
        }
        return fallback;
    }

    template <typename F>
    auto transform(F&& f) const {
        if (_hasValue) {
            return MyOptional<decltype(f(_value))>(f(_value));
        }
        return MyOptional<decltype(f(_value))>();
    }
};

// -------------------- Test scaffold --------------------

int main() {
    MyOptional<int> a(10);
    MyOptional<int> b;

    std::cout << "a has value: " << a.hasValue() << "\n";
    std::cout << "b has value: " << b.hasValue() << "\n";

    std::cout << "a value_or(0): " << a.value_or(0) << "\n";
    std::cout << "b value_or(0): " << b.value_or(0) << "\n";

    auto c = a.transform([](int x) { return x * 2; })
              .transform([](int x) { return x + 3; });
    std::cout << "c has value: " << c.hasValue() << "\n";
    std::cout << "c value: " << c.value() << "\n";

    return 0;
}
// MyOptional Exercise
// Implement a simplified optional type with basic functionality.
// Do NOT use std::optional.

#include <iostream>
#include <string>
#include <utility>

template <typename T>
class MyOptional {
private:
    bool _hasValue;
    T _value;

public:
    // Constructors
    MyOptional() : _hasValue(false), _value() {}

    MyOptional(const T& value) : _hasValue(true), _value(value) {}

    MyOptional(T&& value) : _hasValue(true), _value(std::move(value)) {}

    // Basic observers
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

    // ============================================================
    // TODO 1: Implement value_or
    //
    // Returns the stored value if present; otherwise returns fallback.
    //
    // Signature:
    // template <typename U>
    // T value_or(U&& fallback) const;
    // ============================================================

    template <typename U>
    T value_or(U&& fallback) const {
        // TODO: implement
    }

    // ============================================================
    // TODO 2: Implement transform
    //
    // Applies a function to the stored value if present and returns
    // a new MyOptional containing the result.
    //
    // Signature:
    // template <typename F>
    // auto transform(F&& f) const -> MyOptional<...>;
    // ============================================================

    template <typename F>
    auto transform(F&& f) const {
        // TODO: implement
    }
};

// -------------------- Test scaffold --------------------

int main() {
    MyOptional<int> a(10);
    MyOptional<int> b;

    std::cout << "a has value: " << a.hasValue() << "\n";
    std::cout << "b has value: " << b.hasValue() << "\n";

    // TODO: test value_or
    // std::cout << a.value_or(0) << "\n";
    // std::cout << b.value_or(0) << "\n";

    // TODO: test transform
    // auto c = a.transform([](int x) { return x * 2; })
    //           .transform([](int x) { return x + 3; });

    return 0;
}
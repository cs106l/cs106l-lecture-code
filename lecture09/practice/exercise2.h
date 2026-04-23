#include <vector>
#include <stdexcept>

template <typename T>
class Stack : public std::vector<T> {
public:
    void push(const T& item);
    void pop();
    T& top();
    bool isEmpty() const;
};

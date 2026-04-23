#include <vector>
#include <stdexcept>

class Stack : private std::vector<int> {
public:
    Stack();
    void push(int item);
    void pop();
    int top();
    bool isEmpty() const;
};

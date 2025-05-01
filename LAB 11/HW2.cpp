#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: operation on an empty stack.";
    }
};

template<typename T>
class Stack {
    vector<T> elems;
public:
    void push(const T& value) {
        elems.push_back(value);
    }
    void pop() {
        if (elems.empty()) throw StackUnderflowException();
        elems.pop_back();
    }
    T& top() {
        if (elems.empty()) throw StackUnderflowException();
        return elems.back();
    }
    const T& top() const {
        if (elems.empty()) throw StackUnderflowException();
        return elems.back();
    }
    bool empty() const noexcept {
        return elems.empty();
    }
    size_t size() const noexcept {
        return elems.size();
    }
};

int main() {
    Stack<int> s;
    try {
        cout << "Pushing 1, 2, 3 onto stack\n";
        s.push(1);
        s.push(2);
        s.push(3);
        cout << "Top element: " << s.top() << "\n";
        cout << "Popping elements:\n";
        while (!s.empty()) {
            cout << s.top() << "\n";
            s.pop();
        }
        cout << "Attempting to pop from empty stack\n";
        s.pop();
    } catch (const StackUnderflowException& e) {
        cout << "Exception caught: " << e.what() << "\n";
    }
    return 0;
}

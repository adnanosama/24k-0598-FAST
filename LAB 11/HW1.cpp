#include <iostream>
using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const {
        return a * b;
    }
};

template<typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y, T z, T w)
      : Base<T>(x, y), c(z), d(w) {}
    T multiplyDerived() const {
        return c * d;
    }
};

int main() {
    Base<int>    b(3, 4);
    Derived<int> d(3, 4, 5, 6);

    cout << "Base multiplication:    " << b.multiplyBase()    << endl;
    cout << "Derived multiplication: " << d.multiplyDerived() << endl;

    return 0;
}

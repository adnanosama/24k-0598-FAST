#include <iostream>
#include <exception>
#include <string>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
    string msg;
public:
    ArrayIndexOutOfBounds(int i, int s) {
        msg = "ArrayIndexOutOfBounds: index " + to_string(i) + " for size " + to_string(s);
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template<typename T>
class SafeArray {
    T* data;
    int sz;
public:
    SafeArray(int n) : data(new T[n]), sz(n) {}
    ~SafeArray() { delete[] data; }
    T& operator[](int i) {
        if (i < 0 || i >= sz) throw ArrayIndexOutOfBounds(i, sz);
        return data[i];
    }
    const T& operator[](int i) const {
        if (i < 0 || i >= sz) throw ArrayIndexOutOfBounds(i, sz);
        return data[i];
    }
    int size() const { return sz; }
};

int main() {
    SafeArray<int> arr(5);
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    try {
        cout << arr[5] << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    try {
        cout << arr[-1] << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}

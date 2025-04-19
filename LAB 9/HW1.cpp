#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class shape{
    float area;
    public:

    virtual float getArea() = 0; // pure virtual function
};

class rectangle : virtual public shape{
    float length, width;
    public:
    rectangle(float l, float w) : length(l), width(w) {}

    float getArea() override {
        return length * width;
    }
};

class triangle : virtual public shape{
    float base, height;
    public:
    triangle(float b, float h) : base(b), height(h) {}

    float getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    float length, width, base, height;
    cout << "Enter length and width of rectangle: ";
    cin >> length >> width;
    rectangle rect(length, width);
    cout << "Area of rectangle: " << rect.getArea() << endl;

    cout << "Enter base and height of triangle: ";
    cin >> base >> height;
    triangle tri(base, height);
    cout << "Area of triangle: " << tri.getArea() << endl;
    return 0;
}
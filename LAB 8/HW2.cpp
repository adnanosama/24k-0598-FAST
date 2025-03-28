#include <iostream>
using namespace std;

class Shape {
    double area;

public:
    
    Shape(double a = 0) : area(a) {}
    
    
    double Area() const {
        return area;    
    }
    
    
    Shape operator+(const Shape& s) {
        return Shape(this->area + s.area);
    }
};

int main() {
    Shape shape1(25.5);
    Shape shape2(30.2); 
    
    Shape shape3 = shape1 + shape2; 
    
    cout << "Total Area: " << shape3.Area() << endl;
    
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class circle{
    float radius;
    public:
    circle(float radius){
        this->radius = radius;
        cout << "circle with radius " << radius << " created" << endl;
    }

    float getArea(){
        return M_PI * radius * radius;
    }
    float getPerimeter(){
        return 2 * M_PI * radius;
    }

};

int main(){
    circle c1(3);
    cout << "Area: " << fixed << setprecision(2) << c1.getArea() << endl;
    cout << "Perimeter: " << fixed << setprecision(2) << c1.getPerimeter() << endl;
    return 0;
}
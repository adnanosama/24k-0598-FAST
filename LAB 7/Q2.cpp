#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    int x, y;
    string color;
    float borderThickness;

public:
    Shape(int x, int y, string c, float b = 0.0) : x(x), y(y), color(c), borderThickness(b) {}

    virtual void draw() {
        cout << "Drawing shape at position (" << x << ", " << y << ") with color " << color << endl;
    }

    virtual float calculateArea() {
        cout << "Calculating area..." << endl;
        return 0.0;
    }

    virtual float calculatePerimeter() {
        cout << "Calculating perimeter..." << endl;
        return 0.0;
    }
};

class Circle : public Shape {
    float radius;
    int centerX, centerY;

public:
    Circle(int x, int y, string c, float b, float r, int cx, int cy) 
        : Shape(x, y, c, b), radius(r), centerX(cx), centerY(cy) {}

    void draw() override {
        cout << "Drawing circle at center (" << centerX << ", " << centerY << ") with radius " << radius << endl;
    }

    float calculateArea() override {
        return 3.14 * radius * radius;
    }

    float calculatePerimeter() override {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
    float width, height;
    int topLeftX, topLeftY;

public:
    Rectangle(int x, int y, string c, float b, float w, float h, int tlx, int tly)
        : Shape(x, y, c, b), width(w), height(h), topLeftX(tlx), topLeftY(tly) {}

    void draw() override {
        cout << "Drawing rectangle with top-left corner at (" << topLeftX << ", " << topLeftY 
             << ") with width " << width << " and height " << height << endl;
    }

    float calculateArea() override {
        return width * height;
    }

    float calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
    float side1, side2, side3;

public:
    Triangle(int x, int y, string c, float b, float s1, float s2, float s3)
        : Shape(x, y, c, b), side1(s1), side2(s2), side3(s3) {}

    void draw() override {
        cout << "Drawing triangle at position (" << x << ", " << y << ") with sides " 
             << side1 << ", " << side2 << ", " << side3 << endl;
    }

    float calculateArea() override {
        float s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    float calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

class Polygon : public Shape {
    vector<float> sides;

public:
    Polygon(int x, int y, string c, float b, vector<float> s)
        : Shape(x, y, c, b), sides(s) {}

    void draw() override {
        cout << "Drawing polygon at position (" << x << ", " << y << ") with " 
             << sides.size() << " sides." << endl;
    }

    float calculatePerimeter() override {
        float perimeter = 0;
        for (float side : sides) {
            perimeter += side;
        }
        return perimeter;
    }

    float calculateArea() override {
        cout << "Polygon area calculation depends on specific shape." << endl;
        return 0.0;
    }
};

int main() {
    Shape* shapes[4];

    shapes[0] = new Circle(5, 10, "Red", 1.5, 7.0, 8, 12);
    shapes[1] = new Rectangle(2, 3, "Blue", 2.0, 4.0, 6.0, 2, 3);
    shapes[2] = new Triangle(1, 1, "Green", 1.0, 3.0, 4.0, 5.0);
    shapes[3] = new Polygon(0, 0, "Yellow", 1.2, {3.0, 4.0, 5.0, 6.0});

    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << "-----------------------------------" << endl;
        delete shapes[i];
    }

    return 0;
}

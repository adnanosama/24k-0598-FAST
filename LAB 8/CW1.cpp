#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;
    public:
    

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }


    void reduce() {
        int divisor = gcd(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;
        

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }


    
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout<<"Denominator cannot be zero."<< endl;;
        }
        reduce();
    }
    
  
    Fraction operator+(const Fraction &other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction &other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction &other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction &other) const {
        if (other.numerator == 0) {
            cout<<"Division by zero."<< endl;
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }


    bool operator==(const Fraction &other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction &other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction &other) const {
        return other < *this;
    }

    bool operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction &other) const {
        return !(*this < other);
    }


    friend ostream& operator<<(ostream &os, const Fraction &f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        is >> f.numerator >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;

    cout << "Addition: " << f1 + f2 << endl;
    cout << "Subtraction: " << f1 - f2 << endl;
    cout << "Multiplication: " << f1 * f2 << endl;
    cout << "Division: " << f1 / f2 << endl;
    cout << "Comparison: " << (f1 < f2 ? "f1 < f2" : "f1 >= f2") << endl;
    cout << "Comparison: " << (f1 > f2 ? "f1 > f2" : "f1 <= f2") << endl;

    if (f1 == f2) {
        cout << "Fractions are equal." << endl;
    } else {
        cout << "Fractions are not equal." << endl;
    }

    return 0;
}

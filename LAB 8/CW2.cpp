#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class polynomialUtils;


class polynomial{
    vector<int> coeff;
    public:
    polynomial(){
        coeff.push_back(0);
    }
    polynomial(vector<int>& c): coeff(c){}

    polynomial operator+(const polynomial& other) const {
        vector<int> result(max(coeff.size(), other.coeff.size()), 0);
        for (int i = 0; i < coeff.size(); ++i) {
            result[i] += coeff[i];
        }
        for (int i = 0; i < other.coeff.size(); ++i) {
            result[i] += other.coeff[i];
        }
        return polynomial(result);
    }
    polynomial operator-(const polynomial& other) const {
        vector<int> result(max(coeff.size(), other.coeff.size()), 0);
        for (int i = 0; i < coeff.size(); ++i) {
            result[i] += coeff[i];
        }
        for (int i = 0; i < other.coeff.size(); ++i) {
            result[i] -= other.coeff[i];
        }
        return polynomial(result);
    }
    polynomial operator*(const polynomial& other) const {
        vector<int> result(coeff.size() + other.coeff.size() - 1, 0);
        for (int i = 0; i < coeff.size(); ++i) {
            for (int j = 0; j < other.coeff.size(); ++j) {
                result[i + j] += coeff[i] * other.coeff[j];
            }
        }
        return polynomial(result);
    }
    friend ostream& operator<<(ostream& os, const polynomial& p) {
        bool firstTerm = true; 

        for (int i = p.coeff.size() - 1; i >= 0; --i) { 
            int c = p.coeff[i]; 
            if (c == 0) continue; 

            
            if (!firstTerm) {
                os << (c > 0 ? " + " : " - ");
            } else if (c < 0) {
                os << "-"; 
            }

            
            if (abs(c) != 1 || i == 0) {
                os << abs(c);
            }

            
            if (i > 0) {
                os << "x";
                if (i > 1) os << "^" << i; 
            }

            firstTerm = false; 
            }

            if (firstTerm) os << "0"; 

        return os;
    }
    friend class polynomialUtils;

};

class polynomialUtils {
    public:
        static int evaluate(const polynomial& p, int x) {
            int result = 0;
            for (int i = p.coeff.size() - 1; i >= 0; --i) {
                result = result * x + p.coeff[i];
            }
            return result;
        }
    
        static polynomial derivative(const polynomial& p) {
            if (p.coeff.size() < 2) return polynomial();
            vector<int> deriv(p.coeff.size() - 1, 0);
            for(int i = 1; i < p.coeff.size(); ++i) {
                deriv[i - 1] = p.coeff[i] * static_cast<int>(i);
            }
            return polynomial(deriv);
        }
    };

    int main(){
        vector<int> coeff1 = {1, 2, 3}; // Represents 3x^2 + 2x + 1
        vector<int> coeff2 = {4, 5}; // Represents 5x + 4

        polynomial p1(coeff1);
        polynomial p2(coeff2);

        cout << "Polynomial 1: " << p1 << endl;
        cout << "Polynomial 2: " << p2 << endl;

        polynomial sum = p1 + p2;
        polynomial diff = p1 - p2;
        polynomial prod = p1 * p2;

        cout << "Sum: " << sum << endl;
        cout << "Difference: " << diff << endl;
        cout << "Product: " << prod << endl;

        int x = 2;
        cout << "Evaluation of Polynomial 1 at x=" << x << ": " << polynomialUtils::evaluate(p1, x) << endl;
        cout << "Derivative of Polynomial 1: " << polynomialUtils::derivative(p1) << endl;
    }
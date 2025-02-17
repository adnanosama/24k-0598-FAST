#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class polynimial{
    double *coeffeciants;
    int degree;
    public:
    polynimial(){
        degree=0;
        coeffeciants = new double[1]();
    }
    polynimial(int d, double* arr): degree(d){
        coeffeciants = new double[degree+1]();

        for (int i = 0; i <= degree; ++i) {
            coeffeciants[i] = arr[i];
        }
    }
    polynimial(const polynimial& other) : degree(other.degree) {
        coeffeciants = new double[degree+1]();
        for (int i = 0; i <= degree; ++i) {
            coeffeciants[i] = other.coeffeciants[i];
        }
    }
    polynimial(polynimial&& p) noexcept : degree(p.degree), coeffeciants(p.coeffeciants){
        p.degree=0;
        p.coeffeciants=nullptr;
    }
    ~polynimial() {
        delete[] coeffeciants;
    }
    int getdegree(){
        return degree;
    }
    double evaluate(double x) const{
        double result=0;
        for (int i = 0; i <= degree; ++i) {
            result+=coeffeciants[i]*pow(x,i);
        }
        return result;
    }
    polynimial add(const polynimial& other) const{
        int newdegree = max(degree,other.degree);
        double* newcoeffeciants = new double[newdegree+1]();
        for (int i = 0; i <= newdegree; ++i) {
            if (i<=degree && i<=other.degree) {
                newcoeffeciants[i]=coeffeciants[i]+other.coeffeciants[i];
            }else if (i<=degree) {
                newcoeffeciants[i]=coeffeciants[i];
            }else{
                newcoeffeciants[i]=other.coeffeciants[i];
            }
        }
        polynimial result(newdegree,newcoeffeciants);
        return result;
    }
    polynimial multiply(const polynimial& other) const {
        int newdegree = degree + other.degree;
        double newcoeffeciants[newdegree + 1] = {0}; 
    
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newcoeffeciants[i + j] += coeffeciants[i] * other.coeffeciants[j];
            }
        }
    
        return polynimial(newdegree, newcoeffeciants);
    }
    
};

int main(){
    double arr1[3]={1,2,3};
    double arr2[3]={4,5,6};
    polynimial p1(2,arr1);
    polynimial p2(2,arr2);
    polynimial p3=p1.add(p2);
    polynimial p4=p1.multiply(p2);
    cout<<p3.evaluate(2)<<endl;
    cout<<p4.evaluate(2)<<endl;
    return 0;
}
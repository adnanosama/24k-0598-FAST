#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float weight;
    float inpound;
    cout << "Enter your weight in kg: "<<endl;
    cin >> weight;
    inpound = weight*2.2;
    cout << fixed << setprecision(2);
    cout << "Your weight in pounds is: "<<inpound<<endl;

}
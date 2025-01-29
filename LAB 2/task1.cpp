#include <iostream>
#include <vector>
using namespace std;

int main(){
    int sum;
    int n;
    cout << "enter number of elements: " << endl;
    cin >> n;
    int* arr=new int[n];
    for (int i = 0; i < n; i++){

    cout << "enter element " << i+1 << ":" << endl;
    cin >> arr[i];
    }
    for (int i = 0; i < n; i++){

    sum+= arr[i];
    }
    cout << "the sum is : " << sum << endl;
}
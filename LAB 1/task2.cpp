#include <iostream>
using namespace std;

int main(){
    int size;
    int sum=0;
    cout << "Enter the size of the array: "<<endl;
    cin >> size;

    int *arr = new int[size]; 
    cout << "Enter the elements of the array: "<<endl;

    for (int i = 0; i < size; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The sum of the elements of the array is: "<<sum<<endl;

    delete[] arr; 
    return 0;
}

#include <iostream>
using namespace std;
void * addtoarray(void* arr, int size, int add){
    
    for (int i = 0; i < size; i++){
        ((int*)arr)[i] += add;
    }
    return arr;
}
int main(){
    int add;
    int n;
    int* arr=new int[n];
    cout << "enter number of elements: " << endl;
    cin >> n;
    cout << "enter number to add to each element: " << endl;
    cin >> add;
    for (int i = 0; i < n; i++)
    {
        cout << "enter element " << i+1 << ":" << endl;
        cin >> arr[i];
    }
    int* result = (int*)addtoarray(arr, n, add);
    cout << "the new array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] <<"\n";
    }
    delete[] arr;
}
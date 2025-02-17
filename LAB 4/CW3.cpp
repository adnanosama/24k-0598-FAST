#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class dynamicArray {
    public:
    int* arr;
    int size;

    dynamicArray(){
        arr = new int[0];
        size = 0;
    }
    dynamicArray(int size){
        arr = new int[size]();
        this->size = size;
    }
    dynamicArray(const dynamicArray& other){
        arr = new int[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    dynamicArray(dynamicArray&& other) noexcept : arr(other.arr), size(other.size){
        other.arr = nullptr;
        other.size = 0;
    }
    dynamicArray& operator=(const dynamicArray& other){
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        arr = new int[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        return *this;
    }
    dynamicArray& operator=(dynamicArray&& other) noexcept{
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        arr = other.arr;
        size = other.size;
        other.arr = nullptr;
        other.size = 0;
        return *this;
    }
    ~dynamicArray(){
        delete[] arr;
    }
    int getSize() const {
        return size;
    }
    int& at(int index){
        if(index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    const int& at(int index) const{
        if(index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    void resize(int newsize){
        int* newarr = new int[newsize]();
        for (int i = 0; i < min(size,newsize); i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        size = newsize;
    }

};
int main(){
    dynamicArray a(5);
    for (int i = 0; i < a.getSize(); i++) {
        a.at(i) = i;
    }
    dynamicArray b = a;
    dynamicArray c(move(a));
    for (int i = 0; i < b.getSize(); i++) {
        cout << b.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < c.getSize(); i++) {
        cout<<c.at(i)<<" ";
    }
    cout<<endl;
    return 0;
}
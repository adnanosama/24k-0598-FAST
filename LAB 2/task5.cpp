#include <iostream>
using namespace std;

struct person{
    string name;
    int ID;
};
int sortID(person p[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].ID > p[j+1].ID){
                person temp= p[j];
                p[j]= p[j+1];
                p[j+1]= temp;
            }
        }
    }
    return 0;
}

int sortName(person p[], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(p[j].name > p[j+1].name){
                person temp= p[j];
                p[j]= p[j+1];
                p[j+1]= temp;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;
    person p[n];
    for(int i=0; i<n; i++){
        cout << "Enter the name of person " << i+1 << ": ";
        cin >> p[i].name;
        cout << "Enter the ID of person " << i+1 << ": ";
        cin >> p[i].ID;
    }
    sortID(p, n);
    cout << "Sorted by ID: " << endl;
    for(int i=0; i<n; i++){
        cout << "Name: " << p[i].name << " ID: " << p[i].ID << endl;
    }
    sortName(p, n);
    cout << "Sorted by Name: " << endl;
    for(int i=0; i<n; i++){
        cout << "Name: " << p[i].name << " ID: " << p[i].ID << endl;
    }
    return 0;
}
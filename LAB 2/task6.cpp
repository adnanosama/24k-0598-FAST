#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct subject{
    string name;
};
struct student{
    int ID;
    subject sub[5];
};

int main(){
    int n;
    cout << "enter the number of students: ";
    cin >> n;
    vector<student> std(n);
    for(int i=0; i<n; i++){
        cout << "Enter the ID of student " << i+1 << ": ";
        cin >> std[i].ID;
        for(int j=0; j<5; j++){
            cout << "Enter the name of subject " << j+1 << ": ";
            cin >> std[i].sub[j].name;
        }
    }
    for(int i=0; i<n; i++){
        cout << "Student ID: " << std[i].ID << endl;
        for(int j=0; j<5; j++){
            cout << "Subject " << j+1 << ": " << std[i].sub[j].name << endl;
        }
    }
    
}
#include<iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int isize;
    int n;
    int i=1;
    string choice;
    cout << "Enter the number of elements you want to add: ";
    cin >> isize;

    vector<string> arr(isize);
    cout << "enter no to stop adding elements" << endl;
    cout << "enter element 1: ";
    cin >> arr[0];
    while (i < arr.size())
    {
        cout << "enter element " << i+1 << ": ";
        cin >> arr[i];
        if (arr[i] == "no")
        {
            arr[i] = "";
            break;
        }
        if (i == isize - 1)
        {
            cout << "Array is full, do you want to add more?" << endl;
            cin >> choice;
            if (choice == "yes")
            {
                cout << "how many more elements do you want to add?" << endl;
                cin >> n;
                isize += n;
                arr.resize(isize);
            }
            else
            {
                break;
            }
        }
        i++;
    }
    
    cout << "The elements in the array are:\n ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    
}
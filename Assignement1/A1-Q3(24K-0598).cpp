#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class vehicle{
    string name;
    double rentprice;
    string eleigibilitytype;
    public:
    vehicle(string n, double r, string e){
        name = n;
        rentprice = r;
        eleigibilitytype = e;
    }
    string getname(){
        return name;
    }

    void displayDetails() {
        cout << "Vehicle Name: " << name << endl;
        cout << "Rent Price: " << rentprice << endl;
        cout << "Eligibility Type: " << eleigibilitytype << endl;
        cout << endl;
    }
    string geteleigibilitytype(){
        return eleigibilitytype;
    }
};

class user{
    string name;
    int age;
    string licensetype;
    int contact;
    string userID;
    public:
    user(string n,int a, string l, int c, string u){
        name = n;
        age = a;
        licensetype = l;
        contact = c;
        userID = u;
    }
    void updatename(string n){
        name = n;
    }
    void updateage(int a){
        age = a;
    }
    void updatelicence(string l){
        licensetype = l;
    }
    void getname(){
        cout << name << endl;
    }
    string geteleigibilitytype(){
        return licensetype;
    }
};

int main(){
    
    vehicle *carlist;
    carlist = new vehicle[5]{
        vehicle("car1", 1000, "learner"),
        vehicle("car2", 2000, "intermediate"),
        vehicle("car3", 3000, "full"),
        vehicle("car4", 4000, "intermediate"),
        vehicle("car5", 5000, "full")
    };
    int choice=-1;
    string name;
    int age;
    string licensetype;
    int contact;
    string userID;
    cout << "enter user details to login" << endl;
    
    cout << "User ID: ";
    cin >> userID;
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "License Type: ";
    cin >> licensetype;
    cout << "Contact: ";
    cin >> contact;
    user currentUser(name, age, licensetype, contact, userID);
    while (choice!=0)
    {
        cout << "1.update user details" << endl;
        cout << "2.view car list" << endl;
        cout << "3.rent a car" << endl;
        cout << "0.exit" << endl;
        cin >> choice;

        int choice2;
        string newName;
        int newAge;
        string newLicense;
        string carName;
        bool carFound;

        switch (choice) {
            case 1:
                cout <<"1.update name" << endl;
                cout <<"2.update age" << endl;
                cout <<"3.update license type" << endl;
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        cout << "Enter new name: ";
                        cin >> newName;
                        currentUser.updatename(newName);
                        break;
                    case 2:
                        cout << "Enter new age: ";
                        cin >> newAge;
                        currentUser.updateage(newAge);
                        break;
                    case 3:
                        cout << "Enter new license type: ";
                        cin >> newLicense;
                        currentUser.updatelicence(newLicense);
                        break;
                    default:
                        cout << "Invalid choice, please try again." << endl;
                        break;
                }
                break;
            case 2:
                for(int i = 0; i < 5; i++) {
                    carlist[i].displayDetails();
                }
                break;
            case 3:
                cout << "Enter car name to rent: ";
                cin >> carName;
                carFound = false;
                for(int i=0; i<5; i++){
                    if(carlist[i].getname()==carName){
                        carFound = true;
                        if(currentUser.geteleigibilitytype()==carlist[i].geteleigibilitytype()){
                            cout << "Car rented successfully" << endl;
                            cout << "Car details: " << endl;
                            carlist[i].displayDetails();
                        }
                        else{
                            cout << "You not eligible to rent this car, check your license type" << endl;
                        }
                        break;
                    }
                }
                
                if (!carFound) {
                    cout << "Car not found in the list." << endl;
                }
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
}
    return 0;
}
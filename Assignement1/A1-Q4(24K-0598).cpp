#include <iostream>
#include <string>
using namespace std;

class student {
    string name;
    string rollno;
    string home_address;
    bool card;
    static const int semesterfee = 100000;

public:
    student() : name(""), rollno(""), home_address(""), card(false) {}

    student(string n, string r, string h) : name(n), rollno(r), home_address(h), card(false) {}

    student& operator=(const student& other) {
        if (this != &other) {
            name = other.name;
            rollno = other.rollno;
            home_address = other.home_address;
            card = other.card;
        }
        return *this;
    }

    void registertransportservices() {
        cout << "Student " << name << " with roll number " << rollno << " has registered for transport services." << endl;
        cout << "The home address of the student is " << home_address << endl;
    }

    void paysemesterfee() {
        cout << "The semester fee of the student " << name << " with roll number " << rollno << " is " << semesterfee << endl;
        cout << "Enter amount to pay: ";
        int amount;
        cin >> amount;
        if (amount == semesterfee) {
            cout << "The student has paid the semester fee." << endl;
            cout << "The card has been issued to the student." << endl;
            card = true;
        } else if (amount > semesterfee) {
            cout << "The student has paid the semester fee. The extra amount will be refunded." << endl;
            card = true;
        } else {
            cout << "Insufficient amount. Please pay the full semester fee." << endl;
            card = false;
        }
    }

    void tapcard() {
        if (card) {
            cout << "The card has been tapped." << endl;
            cout << "Attendance marked." << endl;
        } else {
            cout << "The card has not been issued." << endl;
        }
    }

    string getHomeAddress() {
        return home_address;
    }

    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Home Address: " << home_address << endl;
    }
};

class Bus {
    string* stops;
    int busno;
    int numStops;

public:
    Bus() : busno(0), numStops(5) {
        stops = new string[5]{"s1", "s2", "s3", "s4", "s5"};
    }

    Bus(int bn, int numStops) {
        this->busno = bn;
        this->numStops = numStops;
        this->stops = new string[numStops];
    
        cin.ignore(); 
        for (int i = 0; i < numStops; i++) {
            cout << "Enter stop " << i + 1 << ": ";
            getline(cin, this->stops[i]); 
        }
    }
    Bus(const Bus& other) : busno(other.busno), numStops(other.numStops) {
        stops = new string[numStops];
        for (int i = 0; i < numStops; ++i) {
            stops[i] = other.stops[i];
        }
    }
    Bus& operator=(const Bus& other) {
        if (this != &other) {
            delete[] stops;
            busno = other.busno;
            numStops = other.numStops;
            stops = new string[numStops];
            for (int i = 0; i < numStops; ++i) {
                stops[i] = other.stops[i];
            }
        }
        return *this;
    }
    

    int getbusno() { return busno; }

    string getstops(int i) {
        if (i >= 0 && i < numStops)  
        {
            return stops[i];
        }
        return "INVALID";  
    }
    

    ~Bus() {
        delete[] stops;
    }
};

int main() {
    int choice;
    Bus* buslist;
    cout << "Enter number of buses: ";
    int buses;
    cin >> buses;
    buslist = new Bus[buses];

    for (int i = 0; i < buses; i++) {
        cout << "Enter bus number: ";
        int busno;
        cin >> busno;
        buslist[i] = Bus(busno, 5);
    }

    student s1;
    while (true) {
        cout << "1. Register for transport services" << endl;
        cout << "2. Pay semester fee" << endl;
        cout << "3. Tap card" << endl;
        cout << "4. Display student info" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program." << endl;
            break;
        }

        string name, rollno, home_address;
        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter roll number: ";
            cin >> rollno;
            cin.ignore();
            cout << "Enter home address: ";
            getline(cin, home_address);
            s1 = student(name, rollno, home_address);
            s1.registertransportservices();

            for (int i = 0; i < buses; i++) {
                for (int j = 0; j < 5; j++) {
                    string stop = buslist[i].getstops(j);
                    if (stop == home_address) {
                        cout << "Your assigned Bus number is " << buslist[i].getbusno() << " which services your address." << endl;
                        break;
                    }
                }
            }
            break;

        case 2:
            if(s1.getHomeAddress() == "") {
                cout << "Please register for transport services first." << endl;
                break;
            }
            s1.paysemesterfee();
            break;

        case 3:
            s1.tapcard();
            break;

        case 4:
            s1.displayStudentInfo();
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    delete[] buslist;
    return 0;
}

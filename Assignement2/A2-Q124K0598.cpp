#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string id;
    string home_address;
    bool card;

public:
    User(string n, string i, string h) : name(n), id(i), home_address(h), card(false) {}

    virtual ~User() {}

    virtual void payFee() = 0; 

    virtual void registerTransportServices() {
        cout << name << " (ID: " << id << ") has registered for transport services." << endl;
        cout << "Home Address: " << home_address << endl;
    }

    virtual void tapCard() {
        if (card) {
            cout << "Card tapped. Attendance marked." << endl;
        } else {
            cout << "Card not issued. Please pay the required fee." << endl;
        }
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Home Address: " << home_address << endl;
    }

    string getHomeAddress() const {
        return home_address;
    }

    bool operator==(const User& other) const {
        return (id == other.id);
    }
};

class Student : public User {
    static const int semesterFee = 100000;

public:
    Student(string n, string r, string h) : User(n, r, h) {}

    void payFee() override {
        cout << "Semester fee for student " << name << " is " << semesterFee << endl;
        cout << "Enter amount to pay: ";
        int amount;
        cin >> amount;

        if (amount >= semesterFee) {
            cout << "Payment successful. ";
            if (amount > semesterFee) {
                cout << "Refunded " << (amount - semesterFee) << ". ";
            }
            cout << "Card issued." << endl;
            card = true;
        } else {
            cout << "Insufficient amount. Payment failed." << endl;
            card = false;
        }
    }
};

class Teacher : public User {
    static const int monthlyFee = 20000;

public:
    Teacher(string n, string e, string h) : User(n, e, h) {}

    void payFee() override {
        cout << "Monthly fee for teacher " << name << " is " << monthlyFee << endl;
        cout << "Enter amount to pay: ";
        int amount;
        cin >> amount;

        if (amount >= monthlyFee) {
            cout << "Payment successful. ";
            if (amount > monthlyFee) {
                cout << "Refunded " << (amount - monthlyFee) << ". ";
            }
            cout << "Card issued." << endl;
            card = true;
        } else {
            cout << "Insufficient amount. Payment failed." << endl;
            card = false;
        }
    }
};

class Staff : public User {
    static const int monthlyFee = 15000;

public:
    Staff(string n, string e, string h) : User(n, e, h) {}

    void payFee() override {
        cout << "Monthly fee for staff " << name << " is " << monthlyFee << endl;
        cout << "Enter amount to pay: ";
        int amount;
        cin >> amount;

        if (amount >= monthlyFee) {
            cout << "Payment successful. ";
            if (amount > monthlyFee) {
                cout << "Refunded " << (amount - monthlyFee) << ". ";
            }
            cout << "Card issued." << endl;
            card = true;
        } else {
            cout << "Insufficient amount. Payment failed." << endl;
            card = false;
        }
    }
};

class Bus {
    string* stops;
    int busno;
    int numStops;

public:
    Bus() : busno(0), numStops(5) {
        stops = new string[5]{"Stop1", "Stop2", "Stop3", "Stop4", "Stop5"};
    }

    Bus(int bn, int num) : busno(bn), numStops(num) {
        stops = new string[numStops];
        cin.ignore();
        for (int i = 0; i < numStops; ++i) {
            cout << "Enter stop " << (i + 1) << ": ";
            getline(cin, stops[i]);
        }
    }

    Bus(const Bus& other) : busno(other.busno), numStops(other.numStops) {
        stops = new string[numStops];
        for (int i = 0; i < numStops; ++i) {
            stops[i] = other.stops[i];
        }
    }


    ~Bus() {
        delete[] stops;
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

    bool operator==(const Bus& other) const {
        if (busno != other.busno || numStops != other.numStops) return false;
        for (int i = 0; i < numStops; ++i) {
            if (stops[i] != other.stops[i]) return false;
        }
        return true;
    }

    int getBusNumber() const { return busno; }
    string getStop(int index) const {
        if (index >= 0 && index < numStops) return stops[index];
        return "INVALID";
    }
    int getNumStops() const { return numStops; }
};

int main() {
    int numBuses;
    cout << "Enter number of buses: ";
    cin >> numBuses;

    Bus* buses = new Bus[numBuses];
    for (int i = 0; i < numBuses; ++i) {
        int busNumber, numStops;
        cout << "Enter bus number for bus " << (i + 1) << ": ";
        cin >> busNumber;
        cout << "Enter number of stops: ";
        cin >> numStops;
        buses[i] = Bus(busNumber, numStops);
    }

   
    for (int i = 0; i < numBuses; ++i) {
        for (int j = i + 1; j < numBuses; ++j) {
            if (buses[i] == buses[j]) {
                cout << "Bus " << buses[i].getBusNumber() << " and Bus " << buses[j].getBusNumber() << " are the same." << endl;
            }
        }
    }

    User* currentUser = nullptr;

    while (true) {
        cout << "\n1. Register\n2. Pay Fee\n3. Tap Card\n4. Display Info\n5. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if (choice == 5) {
            delete currentUser;
            break;
        }

        switch (choice) {
            case 1: {
                if (currentUser != nullptr) {
                    delete currentUser;
                    currentUser = nullptr;
                }

                int userType;
                cout << "Enter user type \n1. Student\n2. Teacher\n3. Staff\n ";
                cin >> userType;
                cin.ignore();

                string name, id, address;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter ID: ";
                getline(cin, id);
                cout << "Enter home address: ";
                getline(cin, address);

                switch (userType) {
                    case 1:
                        currentUser = new Student(name, id, address);
                        break;
                    case 2:
                        currentUser = new Teacher(name, id, address);
                        break;
                    case 3:
                        currentUser = new Staff(name, id, address);
                        break;
                    default:
                        cout << "Invalid user type." << endl;
                        continue;
                }

                currentUser->registerTransportServices();
                string addressToCheck = currentUser->getHomeAddress();
                bool found = false;

                for (int i = 0; i < numBuses; ++i) {
                    for (int j = 0; j < buses[i].getNumStops(); ++j) {
                        if (buses[i].getStop(j) == addressToCheck) {
                            cout << "Assigned Bus: " << buses[i].getBusNumber() << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }

                if (!found) {
                    cout << "No bus services your address." << endl;
                }
                break;
            }

            case 2:
                if (currentUser == nullptr) {
                    cout << "Register first." << endl;
                } else {
                    currentUser->payFee();
                }
                break;

            case 3:
                if (currentUser == nullptr) {
                    cout << "Register first." << endl;
                } else {
                    currentUser->tapCard();
                }
                break;

            case 4:
                if (currentUser == nullptr) {
                    cout << "Register first." << endl;
                } else {
                    currentUser->displayInfo();
                }
                break;

            default:
                cout << "Invalid choice." << endl;
        }
    }

    delete[] buses;
    return 0;
}
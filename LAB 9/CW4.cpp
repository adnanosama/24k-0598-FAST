#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;
    vector<string> passengerList;

public:
    Flight(string fn, string dep, string arr, int cap) {
        flightNumber = fn;
        departure = dep;
        arrival = arr;
        capacity = cap;
        bookedSeats = 0;
    }

    bool bookSeat(string passengerName) {
        if (bookedSeats < capacity) {
            bookedSeats++;
            passengerList.push_back(passengerName);
            cout << passengerName << " booked on flight " << flightNumber << endl;
            return true;
        } else {
            cout << "Booking failed: Flight full." << endl;
            return false;
        }
    }

    bool cancelSeat(string passengerName) {
        for (int i = 0; i < passengerList.size(); ++i) {
            if (passengerList[i] == passengerName) {
                passengerList.erase(passengerList.begin() + i);
                bookedSeats--;
                cout << passengerName << " canceled on flight " << flightNumber << endl;
                return true;
            }
        }
        cout << "Cancellation failed: Passenger not found." << endl;
        return false;
    }

    bool upgradeSeat(string passengerName) {
        for (string p : passengerList) {
            if (p == passengerName) {
                cout << passengerName << " upgraded on flight " << flightNumber << endl;
                return true;
            }
        }
        cout << "Upgrade failed: Passenger not found." << endl;
        return false;
    }

    void flightInfo() {
        cout << "Flight: " << flightNumber << " from " << departure << " to " << arrival << endl;
        cout << "Capacity: " << capacity << ", Booked: " << bookedSeats << endl;
    }
};

class Passenger {
private:
    int id;
    string name;

public:
    Passenger(int i, string n) {
        id = i;
        name = n;
    }

    void requestBooking(Flight &f) {
        f.bookSeat(name);
    }

    void requestCancellation(Flight &f) {
        f.cancelSeat(name);
    }

    void requestUpgrade(Flight &f) {
        f.upgradeSeat(name);
    }
};

int main() {
    Flight f1("PK101", "Lahore", "Karachi", 2);
    Flight f2("PK202", "Islamabad", "Dubai", 1);

    Passenger p1(1, "Ali");
    Passenger p2(2, "Sara");
    Passenger p3(3, "Ahmed");

    f1.flightInfo();
    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); // Should fail due to capacity

    f1.flightInfo();

    p2.requestUpgrade(f1);
    p2.requestCancellation(f1);

    f1.flightInfo();

    p3.requestBooking(f1); 
    f1.flightInfo();
    

    p2.requestBooking(f2);
    p2.requestCancellation(f2);
    f2.flightInfo();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class vehicles{
    float price;

public:

    vehicles(float p) : price(p) {}


    void setPrice(float p) {
        price = p;
    }


    float getPrice() const {
        return price;
    }
};

class car: public vehicles{
    int seats;
    int doors;
    string fueltype;
    public:
    car(int s, int d, string f) : vehicles(50000), seats(s), doors(d), fueltype(f) {}
    car() : vehicles(0) {
        seats = 0;
        doors = 0;
        fueltype = "";
    }
    int getSeats() const {
        return seats;
    }
    int getDoors() const {
        return doors;
    }
    string getFuelType() const {
        return fueltype;
    }

};

class motorcycle: public vehicles{
    int cylinders;
    int gears;
    int wheels;
    public:
    motorcycle(int c, int g, int w) : vehicles(30000), cylinders(c), gears(g), wheels(w) {}
    motorcycle() : vehicles(0) {
        cylinders = 0;
        gears = 0;
        wheels = 0;
    }
    int getCylinders() const {
        return cylinders;
    }
    int getGears() const {
        return gears;
    }
    int getWheels() const {
        return wheels;
    }

};

class audi: public car{
    string model;
    public:
    audi(string m) : car(4, 4, "Petrol"), model(m) {}
    audi() : car() {
        model = "";
    }
    string getModel() const {
        return model;
    }
    void setModel(string m) {
        model = m;
    }
    void displayInfo() {
        cout << "Model: " << model << ", Seats: " << getSeats() << ", Doors: " << getDoors() << ", Fuel Type: " << getFuelType() << ", Price: " << getPrice() << endl;
    }
};

class yamaha: public motorcycle{
    string make;
    public:
    yamaha(string m, string c) : motorcycle(2, 5, 2), make(m) {}
    yamaha() : motorcycle() {
        make = "";
    }
    string getMake() const {
        return make;
    }

    void setMake(string m) {
        make = m;
    }

    void displayInfo() {
        cout << "Make: " << make << ", Cylinders: " << getCylinders() << ", Gears: " << getGears() << ", Wheels: " << getWheels() << ", Price: " << getPrice() << endl;
    }

};

int main(){
    audi a("A4");
    a.displayInfo();
    yamaha y("R1", "Yamaha");
    y.displayInfo();
    return 0;
}
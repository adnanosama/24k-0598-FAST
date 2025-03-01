#include <iostream>
#include <string>
using namespace std;

class Car {
        string name;
        int model;
    public:
        Car(): name("null"), model(0) {}
        Car(string name, int model) : name(name), model(model) {}
        string getName() { return name; }
        int getModel() { return model; }
};

class Garage {
    private:
    Car* cars[3];
    public:
    Garage() {
        for (int i = 0; i < 3; i++)
        {
            cars[i]=0;
        }
        
    }
    void parkCar(Car* car, int index) {
        cars[index] = car;
    }
    void listCars() {
        for (int i = 0; i < 3; i++) {
            cout << cars[i]->getName() << " " << cars[i]->getModel() << endl;
        }
    }
    
};

int main() {
    Car car1("Toyota", 2021);
    Car car2("Honda", 2022);
    Car car3("Suzuki", 2023);
    Garage g;
    g.parkCar(&car1, 0);
    g.parkCar(&car2, 1);
    g.parkCar(&car3, 2);
    g.listCars();
}
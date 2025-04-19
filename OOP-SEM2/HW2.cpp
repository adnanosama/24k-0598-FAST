#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    double getPrice() {
        return price;
    }

    
    virtual void setPrice(double p) = 0;

    
    virtual ~Car() {}
};


class Color : public Car {
private:
    string color;

public:
    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    void setPrice(double p) override {
        
        price = p * 1.05;
    }

    void displayInfo() {
        cout << "Color Car - Model: " << model << ", Price: " << price << ", Color: " << color << endl;
    }
};


class Company : public Car {
private:
    string companyName;

public:
    void setCompanyName(string name) {
        companyName = name;
    }

    string getCompanyName() {
        return companyName;
    }

    void setPrice(double p) override {
        
        price = p * 0.90;
    }

    void displayInfo() {
        cout << "Company Car - Model: " << model << ", Price: " << price << ", Company: " << companyName << endl;
    }
};


int main() {
  
    Color colorCar;
    colorCar.setModel("Civic");
    colorCar.setColor("Red");
    colorCar.setPrice(20000);
    colorCar.displayInfo();


    Company companyCar;
    companyCar.setModel("Corolla");
    companyCar.setCompanyName("Toyota");
    companyCar.setPrice(25000);
    companyCar.displayInfo();

    return 0;
}

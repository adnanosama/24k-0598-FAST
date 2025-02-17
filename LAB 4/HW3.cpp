#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class invoice{
    string partnumber;
    string description;
    int quantity;
    double price;
    public:
    invoice(string partnumber, string description, int quantity, double price): partnumber(partnumber), description(description), quantity(quantity), price(price){
        if(quantity<0){
            this->quantity=0;
        }
        if(price<0){
            this->price=0.0;
        }
    }
    double getinvoiceamount(){
        return quantity*price;
    }

};

int main(){
    invoice i1("1234","screw",10,5.0);
    cout << "Invoice amount: " << i1.getinvoiceamount() << endl;
    return 0;
}
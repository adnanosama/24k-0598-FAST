#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

class account{
    double balance;
    public:
    void credit(double amount){
        balance += amount;
    }
    void debits(double amount){
        if(balance - amount < 0){
            cout << "Debit amount exceeded account balance." << endl;
        }else{
            balance -= amount;
        }
    }
    double getBalance(){
        return balance;
    }
};

int main(){
    account a1;
    a1.credit(100);
    a1.debits(50);
    cout << "Balance: " << fixed << setprecision(2) << a1.getBalance() << endl;
    return 0;
}
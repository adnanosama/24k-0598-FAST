#include<iostream>
using namespace std;
class bankaccount {
    protected:
    string accno;
    float balance;
    bool isfreeze;
    mutable float acclimit;
    public:
    bankaccount (string a, float b) : accno(a), balance(b), acclimit(50000) {}
    float getbalance () {
        return balance;
    }
    void withdraw (float amount) {
        balance-=amount;
    }
    void deposit (float amount) {
        if (isfreeze) {
            cout << "Account is frozen. Cannot deposit." << endl;
            return;
        }
        balance += amount;
    }
    void freeze() {
        isfreeze = true;
    }
    void setlimit (float a) const {
        acclimit = a;
    }
    float getlimit () const {
        return acclimit;
    }
};
class savingsaccount: public bankaccount {
public:
    savingsaccount(string a, float b) : bankaccount(a, b) {}
    void interest () {
        balance+=0.1*balance;
    }
};
class buisnessaccount : public bankaccount {
public:
    buisnessaccount(string a, float b) : bankaccount(a, b) {}
    void tax() {
        balance-=0.05*balance;
    }
};
class checkingaccount : public bankaccount {
public:
    checkingaccount(string a, float b) : bankaccount(a, b) {}
    float overdraftlimit=-1000;
    void checkforoverdraft (float a) {
        if ((balance-a)<overdraftlimit) {
            cout<<"You have crossed overdraft limit."<<endl;
        }
    }
};

class customer: public bankaccount{
public:
    customer(string a, float b) : bankaccount(a, b) {}
    void withdraw (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance-=amount;
        }
    }
    void deposit (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance+=amount;
        }
    }
};

class teller: public bankaccount {
public:
    teller(string a, float b) : bankaccount(a, b) {}
    void withdraw (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance-=amount;
        }
    }
    void deposit (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance+=amount;
        }
    }
    void freezeaccount () {
        isfreeze=true;
    }
};

class manager: public bankaccount {
public:
    manager(string a, float b) : bankaccount(a, b) {}
    void withdraw (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance-=amount;
        }
    }
    void deposit (float amount) {
        if (amount>acclimit) {
            cout<<"You have crossed your limit."<<endl;
        }
        else {
            balance+=amount;
        }
    }
    void freezeaccount () {
        isfreeze=true;
    }
    void setlimit (float a) const {
        acclimit=a;
    }
};

class Employee {
    protected:
        string employeeID;
        string name;
    public:
        Employee(string id, string n) : employeeID(id), name(n) {}

        virtual void freezeAccount(bankaccount* acc) {
            acc->freeze();
        }
    };
    
    class Teller : public Employee {
    public:
        Teller(string id, string n) : Employee(id, n) {}
        void freezeAccount(bankaccount* acc) override {
            acc->freeze();

        }
    };
    
    class Manager : public Employee {
    public:
        Manager(string id, string n) : Employee(id, n) {}
        void freezeAccount(bankaccount* acc) override {
            acc->freeze();  
        }
        void setAccountLimit(bankaccount* acc, float newLimit) {
            acc->setlimit(newLimit);  
        }
    };
    
    int main() {
        
        savingsaccount s1("1234", 1000);
        buisnessaccount bu1("5678", 2000);
        checkingaccount c1("9101", 1500);
        customer cu1("1121", 3000);
        teller t1("3141", 4000);
        manager m1("5161", 5000);

       
        s1.interest();
        cout << "Savings account balance after interest: " << s1.getbalance() << endl;

      
        bu1.tax();
        cout << "Business account balance after tax: " << bu1.getbalance() << endl;

       
        c1.checkforoverdraft(2500);
        c1.withdraw(2500);
        cout << "Checking account balance after withdrawal: " << c1.getbalance() << endl;

        
        cu1.deposit(60000);
        cu1.withdraw(60000);
        cout << "Customer account balance: " << cu1.getbalance() << endl;

        
        t1.deposit(60000);
        t1.withdraw(60000);
        cout << "Teller account balance: " << t1.getbalance() << endl;

        
        m1.deposit(60000);
        m1.withdraw(60000);
        m1.setlimit(100000);
        cout << "Manager account balance: " << m1.getbalance() << endl;

        
        Employee* e1 = new Teller("1234", "Ali");
        Employee* e2 = new Manager("5678", "Ahmed");
        e1->freezeAccount(&bu1);
        e2->freezeAccount(&bu1);
        static_cast<Manager*>(e2)->setAccountLimit(&bu1, 100000);
        cout << "Business account limit after manager set limit: " << bu1.getlimit() << endl;

        
        delete e1;
        delete e2;

        return 0;
    }
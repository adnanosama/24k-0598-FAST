#include <iostream>
#include <string>
using namespace std;

class person {
public:
    virtual void getdata() = 0;
    virtual void displaydata() = 0;
    virtual ~person() {}
};

class admin : virtual public person {
protected:
    string adminName;
    string designation;
    float adminSalary;
public:
    void getdata() override {
        cout << "Enter admin name: ";
        getline(cin, adminName);
        cout << "Enter designation: ";
        getline(cin, designation);
        cout << "Enter admin salary: ";
        cin >> adminSalary;
        cin.ignore();
    }

    void displaydata() override {
        cout << "Admin Name: " << adminName << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << adminSalary << endl;
        cout << "Admin Bonus: " << calculateBonus() << endl;
    }

    float calculateBonus()  {
        return 0.1 * adminSalary;
    }
};

class account : virtual public person {
protected:
    string accountName;
    string accountType;
    float accountSalary;
public:
    void getdata() override {
        cout << "Enter account name: ";
        getline(cin, accountName);
        cout << "Enter account type: ";
        getline(cin, accountType);
        cout << "Enter account salary: ";
        cin >> accountSalary;
        cin.ignore();
    }

    void displaydata() override {
        cout << "Account Name: " << accountName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Salary: " << accountSalary << endl;
        cout << "Account Bonus: " << calculateBonus() << endl;
    }

    float calculateBonus(){
        return 0.05 * accountSalary;
    }
};

class master : public admin, public account {
private:
    string masterName;
public:
    void getdata() override {
        cout << "Enter master name: ";
        getline(cin, masterName);

        cout << "\n--- Admin Section ---\n";
        admin::getdata();

        cout << "\n--- Account Section ---\n";
        account::getdata();
    }

    void displaydata() override {
        cout << "\n--- Master Info ---\n";
        cout << "Master Name: " << masterName << endl;

        cout << "\n--- Admin Info ---\n";
        admin::displaydata();

        cout << "\n--- Account Info ---\n";
        account::displaydata();

        cout << "\nTotal Master Bonus: " << calculateBonus() << endl;
    }

    float calculateBonus() {
        return admin::calculateBonus() + account::calculateBonus();
    }
};

int main() {
    person* p;
    master m;
    p = &m;

    p->getdata();
    p->displaydata();

    return 0;
}

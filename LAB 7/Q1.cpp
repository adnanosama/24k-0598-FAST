#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
protected:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;
    vector<string> accountStatement;

public:

    Account(int accNumber, float bal, string holderName, string type)
        : accountNumber(accNumber), balance(bal), accountHolderName(holderName), accountType(type) {}

    virtual ~Account() {} // Virtual destructor

    virtual void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            accountStatement.push_back("Deposited: " + to_string(amount));
            cout << "Amount deposited successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(float amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            accountStatement.push_back("Withdrawn: " + to_string(amount));
            cout << "Amount withdrawn successfully." << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculated for generic account." << endl;
    }

    void getAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void printStatement() const {
        cout << "Transaction History:" << endl;
        for (const auto& transaction : accountStatement) {
            cout << transaction << endl;
        }
    }
};

class SavingsAccount : public Account {
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(int accNumber, float bal, string holderName, float minBalance, float intRate)
        : Account(accNumber, bal, holderName, "Savings"), minimumBalance(minBalance), interestRate(intRate) {}

    void calculateInterest() override {
        balance += balance * interestRate;
        cout << "Interest calculated for savings account." << endl;
    }

    void withdraw(float amount) override {
        if (balance - amount >= minimumBalance) {
            Account::withdraw(amount);
        } else {
            cout << "Withdrawal failed. Minimum balance requirement not met." << endl;
        }
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNumber, float bal, string holderName)
        : Account(accNumber, bal, holderName, "Checking") {}

    // No functionality for now
};

class FixedDepositAccount : public Account {
    float fixedInterestRate;
    string maturityDate;
    int depositCount;

public:
    FixedDepositAccount(int accNumber, float bal, string holderName, string maturity, float intRate)
        : Account(accNumber, bal, holderName, "Fixed Deposit"), maturityDate(maturity), fixedInterestRate(intRate), depositCount(0) {}

    void calculateInterest() override {
        balance += balance * fixedInterestRate;
        cout << "Interest calculated for fixed deposit account." << endl;
    }

    void deposit(float amount) override {
        if (depositCount < 1) {
            Account::deposit(amount);
            depositCount++;
        } else {
            cout << "Deposit failed. Only one deposit allowed for fixed deposit accounts." << endl;
        }
    }

    void withdraw(float amount) override {
        cout << "Withdrawal failed. Funds are locked until maturity date: " << maturityDate << endl;
    }
};

int main() {
    SavingsAccount savings(12345, 1000, "John Doe", 500, 0.05);
    savings.getAccountInfo();
    savings.deposit(500);
    savings.withdraw(200);
    savings.calculateInterest();
    savings.printStatement();


    FixedDepositAccount fixedDeposit(67890, 5000, "Jane Doe", "2025-12-31", 0.10);
    fixedDeposit.getAccountInfo();
    fixedDeposit.deposit(1000);
    fixedDeposit.deposit(500);
    fixedDeposit.withdraw(200); 
    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}
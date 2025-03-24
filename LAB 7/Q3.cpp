#include <iostream>
using namespace std;

class Currency {
    protected:
    int amount;
    int currencyCode;
    char currencySymbol;
    float exchangeRate;
    public:
    Currency(int a, int c, char s, float e) : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(e) {}
    virtual void convertToBase() {
        amount = amount * exchangeRate;
        currencyCode = 1;
        currencySymbol = '$';
        exchangeRate = 1;
    }
    void convertTo(Currency c) {
        amount = amount * exchangeRate / c.exchangeRate;
        currencyCode = c.currencyCode;
        currencySymbol = c.currencySymbol;
        exchangeRate = c.exchangeRate;
    }
    virtual void displayCurrency() {
        cout << "Amount: " << amount << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Dollar : public Currency {
    public:
    Dollar(int a, int c, char s, float e) : Currency(a, c, s, e) {}
    void convertToBase() override {
        amount = amount * exchangeRate;
        currencyCode = 1;
        currencySymbol = '$';
        exchangeRate = 1;
    }
    void displayCurrency() override{
        cout << "Amount: " << amount << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Currency Symbol: " << currencySymbol << endl;
        cout << "Exchange Rate: " << exchangeRate << endl;
    }
};

class Euro : public Currency {
    public:
    Euro(int a, int c, char s, float e) : Currency(a, c, s, e) {}
    void convertToBase() override {
        amount = amount * exchangeRate;
        currencyCode = 2;
        currencySymbol = '€';
        exchangeRate = 0.85;
    }
    void displayCurrency() override {
        Currency::displayCurrency();
    }
};

class Rupee : public Currency {
    public:
    Rupee(int a, int c, char s, float e) : Currency(a, c, s, e) {}
    void convertToBase() {
        amount = amount * exchangeRate;
        currencyCode = 3;
        currencySymbol = '₹';
        exchangeRate = 74.5;
    }
    void displayCurrency() {
        Currency::displayCurrency();
    }
};

int main() {
    Dollar d(100, 1, '$', 1);
    Euro e(100, 2, '€', 0.85);
    Rupee r(100, 3, '₹', 74.5);
    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();
    d.convertToBase();
    e.convertToBase();
    r.convertToBase();
    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();
    return 0;
}
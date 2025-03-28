#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
    vector<int> numDigits;
    bool isNeg;

    void parseString(const string& str) {
        isNeg = (str[0] == '-');
        for (int i = str.size() - 1; i >= (isNeg ? 1 : 0); --i)
            numDigits.push_back(str[i] - '0');
    }

    void trimZeros() {
        while (numDigits.size() > 1 && numDigits.back() == 0)
            numDigits.pop_back();
        if (numDigits.size() == 1 && numDigits[0] == 0)
            isNeg = false;
    }

    static bool isSmallerAbs(const BigInteger& x, const BigInteger& y) {
        if (x.numDigits.size() != y.numDigits.size()) return x.numDigits.size() < y.numDigits.size();
        for (int i = x.numDigits.size() - 1; i >= 0; --i)
            if (x.numDigits[i] != y.numDigits[i]) return x.numDigits[i] < y.numDigits[i];
        return false;
    }

public:
    BigInteger() : isNeg(false) {}

    BigInteger(string str) {
        parseString(str);
    }

    BigInteger(long long val) {
        parseString(to_string(val));
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNeg == other.isNeg) {
            BigInteger res;
            res.isNeg = isNeg;
            int carry = 0, sum;
            size_t i;
            for (i = 0; i < max(numDigits.size(), other.numDigits.size()) || carry; ++i) {
                sum = carry;
                if (i < numDigits.size()) sum += numDigits[i];
                if (i < other.numDigits.size()) sum += other.numDigits[i];
                carry = sum / 10;
                res.numDigits.push_back(sum % 10);
            }
            return res;
        }
        return isNeg ? (other - (-(*this))) : (*this - (-other));
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNeg != other.isNeg) {
            return *this + (-other);
        }
        if (isSmallerAbs(*this, other)) {
            return -(other - *this);
        }
        BigInteger res;
        res.isNeg = isNeg;
        int borrow = 0, diff;
        for (size_t i = 0; i < numDigits.size(); ++i) {
            diff = numDigits[i] - borrow - (i < other.numDigits.size() ? other.numDigits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res.numDigits.push_back(diff);
        }
        res.trimZeros();
        return res;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger res;
        res.numDigits.resize(numDigits.size() + other.numDigits.size(), 0);
        res.isNeg = (isNeg != other.isNeg);
        for (size_t i = 0; i < numDigits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.numDigits.size() || carry; ++j) {
                int product = res.numDigits[i + j] + numDigits[i] * (j < other.numDigits.size() ? other.numDigits[j] : 0) + carry;
                carry = product / 10;
                res.numDigits[i + j] = product % 10;
            }
        }
        res.trimZeros();
        return res;
    }

    BigInteger operator-() const {
        BigInteger res = *this;
        res.isNeg = !isNeg;
        return res;
    }

    bool operator==(const BigInteger& other) const {
        return isNeg == other.isNeg && numDigits == other.numDigits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNeg != other.isNeg) return isNeg;
        return isNeg ? isSmallerAbs(other, *this) : isSmallerAbs(*this, other);
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& out, const BigInteger& num) {
        if (num.isNeg) out << "-";
        for (int i = num.numDigits.size() - 1; i >= 0; --i)
            out << num.numDigits[i];
        return out;
    }

    friend istream& operator>>(istream& in, BigInteger& num) {
        string input;
        in >> input;
        num.parseString(input);
        return in;
    }
};

int main() {
    BigInteger num1, num2;
    cout << "Enter two big integers:\n";
    cin >> num1 >> num2;

    cout << "First Number: " << num1 << "\n";
    cout << "Second Number: " << num2 << "\n";
    cout << "Sum: " << (num1 + num2) << "\n";
    cout << "Difference: " << (num1 - num2) << "\n";
    cout << "Product: " << (num1 * num2) << "\n";

    cout << "Comparison Results:\n";
    cout << "Are they equal? " << (num1 == num2) << "\n";
    cout << "Are they different? " << (num1 != num2) << "\n";
    cout << "Is first smaller? " << (num1 < num2) << "\n";
    cout << "Is first greater? " << (num1 > num2) << "\n";

    return 0;
}

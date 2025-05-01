#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException: Matrix dimensions do not match.";
    }
};

template<typename T>
class Matrix {
    size_t rows, cols;
    vector<vector<T>> data;
public:
    Matrix(size_t r, size_t c, const T& init = T())
        : rows(r), cols(c), data(r, vector<T>(c, init)) {}

    T& operator()(size_t r, size_t c) {
        if (r >= rows || c >= cols) throw out_of_range("Index out of bounds");
        return data[r][c];
    }
    const T& operator()(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw out_of_range("Index out of bounds");
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) throw DimensionMismatchException();
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) throw DimensionMismatchException();
        Matrix<T> result(rows, other.cols, T());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = T();
                for (size_t k = 0; k < cols; ++k) {
                    sum += data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    size_t numRows() const { return rows; }
    size_t numCols() const { return cols; }
};

int main() {
    Matrix<int> A(2, 3, 1);
    Matrix<int> B(2, 3, 2);
    Matrix<int> C = A + B;
    for (size_t i = 0; i < C.numRows(); ++i) {
        for (size_t j = 0; j < C.numCols(); ++j)
            cout << C(i,j) << ' ';
        cout << '\n';
    }

    Matrix<int> X(2, 3, 1);
    Matrix<int> Y(3, 2, 4);
    Matrix<int> Z = X * Y;
    for (size_t i = 0; i < Z.numRows(); ++i) {
        for (size_t j = 0; j < Z.numCols(); ++j)
            cout << Z(i,j) << ' ';
        cout << '\n';
    }

    try {
        A(10,10) = 5;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

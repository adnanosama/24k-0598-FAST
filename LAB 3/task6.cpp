#include <iostream>
#include <string>
using namespace std;

class matrix {
    private:
        int row;
        int col;
        int **elements;
public:
    matrix(int r, int c) {
        row = r;
        col = c;
        elements = new int*[row];
        for (int i = 0; i < row; i++) {
            elements[i] = new int[col];
        }
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
    void setelement(int i, int j, int value) {
        elements[i][j] = value;
    }
    void add(matrix m) {
        if (row == m.getRow() && col == m.getCol()) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    elements[i][j] += m.elements[i][j];
                }
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    cout << elements[i][j] << " ";
                }
                cout << endl;
            }
            cout << "end of added matrix"<<endl;
        }
        else {
            cout << "matrices cannot be added" << endl;
        }
    }
    void multiply(matrix m) {
        if (col == m.getRow()) {
            matrix result(row, m.getCol());
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < m.getCol(); j++) {
                    result.elements[i][j] = 0;
                    for (int k = 0; k < col; k++) {
                        result.elements[i][j] += elements[i][k] * m.elements[k][j];
                    }
                }
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < m.getCol(); j++) {
                    cout << result.elements[i][j] << " ";
                }
               cout << endl;
            }
             cout << "end of multiplied matrix"<<endl;
        }
        else {
            cout << "matrices cannot be multiplied" << endl;
        }
    }
};

int main() {
    
    matrix m1(3, 3);
    m1.setelement(0, 0, 1);
    m1.setelement(0, 1, 2);
    m1.setelement(0, 2, 3);
    m1.setelement(1, 0, 4);
    m1.setelement(1, 1, 5);
    m1.setelement(1, 2, 6);
    m1.setelement(2, 0, 7);
    m1.setelement(2, 1, 8);
    m1.setelement(2, 2, 9);

    matrix m2(3, 3);
    m2.setelement(0, 0, 7);
    m2.setelement(0, 1, 8);
    m2.setelement(0, 2, 9);
    m2.setelement(1, 0, 9);
    m2.setelement(1, 1, 10);
    m2.setelement(1, 2, 11);
    m2.setelement(2, 0, 11);
    m2.setelement(2, 1, 12);
    m2.setelement(2, 2, 13);
    m1.add(m2);
    m1.multiply(m2);
    return 0;
}
#include <iostream>
#include <limits>
using namespace std;

float findSecondHighest(float *array, int *size) {
    
    float max1 = numeric_limits<float>::lowest();
    float max2 = numeric_limits<float>::lowest();

    for (int i = 0; i < *size; i++) {
        if (array[i] > max1) {
            max2 = max1;      
            max1 = array[i];  
        } else if (array[i] > max2 && array[i] != max1) {
            max2 = array[i];  
        }
    }

    return max2;
}

int main() {
    float array[20];
    int size = 20;

    cout << "Enter the values of the array:\n" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the value of element number " << i + 1 << ": ";
        cin >> array[i];
    }

    float secondHighest = findSecondHighest(array, &size);
    if (secondHighest == numeric_limits<float>::lowest()) {
        cout << "No second-highest value found (e.g., all elements are the same)." << endl;
    } else {
        cout << "The second-highest value in the array is: " << secondHighest << endl;
    }

    return 0;
}

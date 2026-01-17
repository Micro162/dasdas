#include <iostream>
#include <string>
using namespace std;

class ArraySizeException {
    string message;
public:
    ArraySizeException(const string& msg) : message(msg) {}
    const char* what() const { return message.c_str(); }
};

class ArrayDataException {
    string message;
public:
    ArrayDataException(const string& msg) : message(msg) {}
    const char* what() const { return message.c_str(); }
};

class ArrayValueCalculator {
public:
    int doCalc(string arr[4][4], int rows, int cols) {
        if (rows != 4 || cols != 4) {
            throw ArraySizeException("Array must be 4x4!");
        }

        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                try {
                    sum += stoi(arr[i][j]); 
                }
                catch (...) { 
                    throw ArrayDataException("Invalid data at [" + to_string(i) + "][" + to_string(j) + "]: '" + arr[i][j] + "'");
                }
            }
        }

        return sum;
    }
};

int main() {
    string arr[4][4] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}
    };

    ArrayValueCalculator calc;

    try {
        int result = calc.doCalc(arr, 4, 4);
        cout << "Sum = " << result << endl;
    }
    catch (ArraySizeException& e) {
        cout << "Array size error: " << e.what() << endl;
    }
    catch (ArrayDataException& e) {
        cout << "Array data error: " << e.what() << endl;
    }

    return 0;
}

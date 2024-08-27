#include <iostream>

using namespace std;

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2;
    char operation;

    // Prompt user for input
    cout << "\n Enter first number: ";
    cin >> num1;
    cout << "\n Enter second number: ";
    cin >> num2;
    cout << "\n Enter an operator (+, -, *, /): ";
    cin >> operation;

    double result;

    // Perform calculation based on the operator
    switch (operation) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            if (num2 != 0) {
                result = divide(num1, num2);
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operator." << endl;
            return 1;
    }

    // Display result
    cout << "\n Result: " << result << endl;

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

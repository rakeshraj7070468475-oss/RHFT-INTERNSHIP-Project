#include <iostream>
#include <limits>
using namespace std;

int main() {
    double num1, num2, result;
    char op;
    char choice;

    cout << "===== SAFE CALCULATOR =====" << endl;

    do {
        try {
            // Input first number
            cout << "\nEnter first number: ";
            if (!(cin >> num1)) {
                throw "Invalid input! Please enter numeric values only.";
            }

            // Input operator
            cout << "Enter operator (+, -, *, /): ";
            cin >> op;

            // Check valid operator
            if (op != '+' && op != '-' && op != '*' && op != '/') {
                throw "Invalid operator! Use only +, -, *, /";
            }

            // Input second number
            cout << "Enter second number: ";
            if (!(cin >> num2)) {
                throw "Invalid input! Please enter numeric values only.";
            }

            // Division by zero check
            if (op == '/' && num2 == 0) {
                throw "Error! Division by zero is not allowed.";
            }

            // Perform calculation
            switch (op) {
                case '+':
                    result = num1 + num2;
                    break;

                case '-':
                    result = num1 - num2;
                    break;

                case '*':
                    result = num1 * num2;
                    break;

                case '/':
                    result = num1 / num2;
                    break;
            }

            cout << "Result: " << result << endl;
        }

        catch (const char* error) {
            cout << error << endl;

            // Clear error state
            cin.clear();

            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Continue option
        cout << "\nDo you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nCalculator closed successfully." << endl;

    return 0;
}
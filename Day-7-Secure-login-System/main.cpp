#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

// Function to check password strength
bool isStrongPassword(const string& password) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    if (password.length() < 8) {
        return false;
    }

    for (char ch : password) {
        if (isupper(ch))
            hasUpper = true;
        else if (islower(ch))
            hasLower = true;
        else if (isdigit(ch))
            hasDigit = true;
        else
            hasSpecial = true;
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    // Predefined credentials
    const string correctUsername = "admin";
    const string correctPassword = "Admin@123";

    string username, password;

    int attempts = 0;
    const int maxAttempts = 3;

    cout << "==============================" << endl;
    cout << "     SECURE LOGIN SYSTEM      " << endl;
    cout << "==============================" << endl;

    // Password strength validation
    cout << "\nChecking system password strength..." << endl;

    if (isStrongPassword(correctPassword)) {
        cout << "System password is STRONG.\n" << endl;
    } else {
        cout << "System password is WEAK.\n" << endl;
    }

    while (attempts < maxAttempts) {
        try {
            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            // Validate credentials
            if (username == correctUsername &&
                password == correctPassword) {

                cout << "\nLogin Successful!" << endl;
                cout << "Welcome, " << username << "!" << endl;
                return 0;
            } else {
                throw runtime_error("Invalid username or password.");
            }

        } catch (const exception& e) {
            attempts++;

            cout << "\nError: " << e.what() << endl;

            int remaining = maxAttempts - attempts;

            if (remaining > 0) {
                cout << "Remaining Attempts: "
                     << remaining << endl << endl;
            } else {
                cout << "\nSystem Locked!" << endl;
                cout << "Too many failed login attempts."
                     << endl;
            }
        }
    }

    return 0;
}
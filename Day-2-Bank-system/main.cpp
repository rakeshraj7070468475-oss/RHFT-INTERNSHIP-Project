#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    double balance;
    const double MIN_BALANCE = 500.0;

public:
    // Constructor enforces valid state
    BankAccount(int accNo, string name, double initialBalance) {
        if (accNo <= 0) throw invalid_argument("Invalid account number");
        if (name.empty()) throw invalid_argument("Name cannot be empty");
        if (initialBalance < MIN_BALANCE)
            throw invalid_argument("Initial balance must be >= minimum balance");

        accountNumber = accNo;
        holderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0)
            throw invalid_argument("Deposit must be positive");

        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0)
            throw invalid_argument("Withdrawal must be positive");

        if (balance - amount < MIN_BALANCE)
            throw runtime_error("Cannot go below minimum balance");

        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Account: " << accountNumber
             << ", Name: " << holderName
             << ", Balance: " << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;

    try {
        accounts.emplace_back(101, "Rakesh", 1000);
        accounts.emplace_back(102, "Amit", 2000);
    } catch (exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;

        int accNo;
        double amount;

        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Enter Account Number: ";
            cin >> accNo;
        }

        // find account
        BankAccount* acc = nullptr;
        for (auto& a : accounts) {
            if (a.getBalance() >= 0) { // dummy check to iterate
                // match account
                if (accNo == 101 || accNo == 102) {
                    acc = &a;
                }
            }
        }

        if (!acc && choice != 4) {
            cout << "Account not found\n";
            continue;
        }

        try {
            switch (choice) {
                case 1:
                    cout << "Enter amount: ";
                    cin >> amount;
                    acc->deposit(amount);
                    break;

                case 2:
                    cout << "Enter amount: ";
                    cin >> amount;
                    acc->withdraw(amount);
                    break;

                case 3:
                    acc->display();
                    break;
            }
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 4);

    return 0;
}
// ==============================
// FILE: main.cpp
// ==============================

#include <iostream>
#include "Cart.h"

using namespace std;

int main() {

    Cart cart;

    int choice;

    do {

        cout << "\n========== MINI SHOPPING CART ==========\n";

        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. View Cart\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {

                int id, quantity;
                string name;
                double price;

                cout << "\nEnter Product ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Product Name: ";
                getline(cin, name);

                cout << "Enter Product Price: ";
                cin >> price;

                cout << "Enter Quantity: ";
                cin >> quantity;

                // Validation
                if (price <= 0 || quantity <= 0) {
                    cout << "Invalid price or quantity.\n";
                    break;
                }

                Product p(id, name, price, quantity);

                cart.addProduct(p);

                break;
            }

            case 2: {

                int id;

                cout << "\nEnter Product ID to remove: ";
                cin >> id;

                cart.removeProduct(id);

                break;
            }

            case 3: {

                cart.displayCart();

                break;
            }

            case 4: {

                cart.displayBillSummary();

                break;
            }

            case 5: {

                cout << "\nExiting Program...\n";

                break;
            }

            default:
                cout << "\nInvalid choice.\n";
        }

    } while(choice != 5);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ================= BASE CLASS =================
class Item {
protected:
    int id;
    string title;
    bool issued;

public:
    // Constructor
    Item(int i, string t) {
        id = i;
        title = t;
        issued = false;
    }

    // Virtual function for polymorphism
    virtual void displayDetails() {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }

    // Issue item
    void issueItem() {
        if (!issued) {
            issued = true;
            cout << "Item issued successfully.\n";
        } else {
            cout << "Item already issued.\n";
        }
    }

    // Return item
    void returnItem() {
        if (issued) {
            issued = false;
            cout << "Item returned successfully.\n";
        } else {
            cout << "Item was not issued.\n";
        }
    }

    // Check availability
    bool isAvailable() {
        return !issued;
    }

    // Getter for ID
    int getId() {
        return id;
    }

    // Fine calculation
    int calculateFine(int daysLate) {
        if (daysLate <= 0)
            return 0;

        return daysLate * 5;
    }

    // Virtual destructor
    virtual ~Item() {}
};

// ================= DERIVED CLASS: BOOK =================
class Book : public Item {
private:
    string author;

public:
    // Constructor
    Book(int i, string t, string a)
        : Item(i, t) {
        author = a;
    }

    // Override displayDetails
    void displayDetails() override {
        cout << "\n===== BOOK DETAILS =====";
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (issued ? "Issued" : "Available");
        cout << "\n========================\n";
    }
};

// ================= DERIVED CLASS: MAGAZINE =================
class Magazine : public Item {
private:
    int issueNumber;

public:
    // Constructor
    Magazine(int i, string t, int issueNo)
        : Item(i, t) {
        issueNumber = issueNo;
    }

    // Override displayDetails
    void displayDetails() override {
        cout << "\n=== MAGAZINE DETAILS ===";
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nIssue Number: " << issueNumber;
        cout << "\nStatus: " << (issued ? "Issued" : "Available");
        cout << "\n========================\n";
    }
};

// ================= HELPER FUNCTIONS =================

// Find item by ID
Item* findItemById(vector<Item*>& library, int id) {
    for (Item* item : library) {
        if (item->getId() == id) {
            return item;
        }
    }
    return nullptr;
}

// Count available items
void countAvailableItems(vector<Item*>& library) {
    int count = 0;

    for (Item* item : library) {
        if (item->isAvailable()) {
            count++;
        }
    }

    cout << "\nAvailable Items: " << count << endl;
}

// Display all items
void displayAllItems(vector<Item*>& library) {
    if (library.empty()) {
        cout << "\nLibrary is empty.\n";
        return;
    }

    for (Item* item : library) {
        item->displayDetails();
    }
}

// ================= MAIN FUNCTION =================
int main() {
    vector<Item*> library;

    int choice;

    do {
        cout << "\n========== LIBRARY SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Magazine\n";
        cout << "3. Display All Items\n";
        cout << "4. Issue Item\n";
        cout << "5. Return Item\n";
        cout << "6. Count Available Items\n";
        cout << "7. Calculate Fine\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int id;
            string title, author;

            cin.ignore();

            cout << "Enter Book ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            library.push_back(new Book(id, title, author));

            cout << "Book added successfully.\n";
            break;
        }

        case 2: {
            int id, issueNo;
            string title;

            cout << "Enter Magazine ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Magazine Title: ";
            getline(cin, title);

            cout << "Enter Issue Number: ";
            cin >> issueNo;

            library.push_back(new Magazine(id, title, issueNo));

            cout << "Magazine added successfully.\n";
            break;
        }

        case 3: {
            displayAllItems(library);
            break;
        }

        case 4: {
            int id;

            cout << "Enter Item ID to issue: ";
            cin >> id;

            Item* item = findItemById(library, id);

            if (item != nullptr) {
                item->issueItem();
            } else {
                cout << "Item not found.\n";
            }

            break;
        }

        case 5: {
            int id;

            cout << "Enter Item ID to return: ";
            cin >> id;

            Item* item = findItemById(library, id);

            if (item != nullptr) {
                item->returnItem();
            } else {
                cout << "Item not found.\n";
            }

            break;
        }

        case 6: {
            countAvailableItems(library);
            break;
        }

        case 7: {
            int id, daysLate;

            cout << "Enter Item ID: ";
            cin >> id;

            Item* item = findItemById(library, id);

            if (item != nullptr) {
                cout << "Enter number of late days: ";
                cin >> daysLate;

                int fine = item->calculateFine(daysLate);

                cout << "Fine Amount: Rs. " << fine << endl;
            } else {
                cout << "Item not found.\n";
            }

            break;
        }

        case 8:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 8);

    // Memory cleanup
    for (Item* item : library) {
        delete item;
    }

    library.clear();

    return 0;
}
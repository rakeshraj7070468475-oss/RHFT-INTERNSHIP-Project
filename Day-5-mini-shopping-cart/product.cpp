// ==============================
// FILE: Product.cpp
// ==============================

#include "Product.h"

// Constructor
Product::Product(int id, string name, double price, int quantity) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

// Getters
int Product::getId() const {
    return id;
}

string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

// Setter
void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Total Price
double Product::getTotalPrice() const {
    return price * quantity;
}

// Display Product
void Product::displayProduct() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Total: " << getTotalPrice() << endl;
}
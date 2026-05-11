// ==============================
// FILE: Product.h
// ==============================

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Product(int id = 0, string name = "", double price = 0.0, int quantity = 0);

    // Getters
    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setQuantity(int quantity);

    // Functions
    double getTotalPrice() const;
    void displayProduct() const;
};

#endif
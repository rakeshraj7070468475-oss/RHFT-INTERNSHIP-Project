// ==============================
// FILE: Cart.h
// ==============================

#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"

class Cart {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product);
    void removeProduct(int id);
    void displayCart() const;
    double calculateSubtotal() const;
    double calculateDiscount(double subtotal) const;
    double calculateFinalTotal() const;
    void displayBillSummary() const;
};

#endif
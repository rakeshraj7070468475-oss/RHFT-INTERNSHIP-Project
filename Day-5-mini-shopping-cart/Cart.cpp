// ==============================
// FILE: Cart.cpp
// ==============================

#include "Cart.h"

void Cart::addProduct(const Product& product) {

    // Check if product already exists
    for (auto &p : products) {
        if (p.getId() == product.getId()) {

            // Increase quantity
            int newQuantity = p.getQuantity() + product.getQuantity();
            p.setQuantity(newQuantity);

            cout << "Product quantity updated successfully.\n";
            return;
        }
    }

    // Add new product
    products.push_back(product);

    cout << "Product added to cart.\n";
}

void Cart::removeProduct(int id) {

    for (auto it = products.begin(); it != products.end(); it++) {

        if (it->getId() == id) {
            products.erase(it);

            cout << "Product removed successfully.\n";
            return;
        }
    }

    cout << "Product not found.\n";
}

void Cart::displayCart() const {

    if (products.empty()) {
        cout << "\nCart is empty.\n";
        return;
    }

    cout << "\n========== CART ITEMS ==========\n";

    for (const auto &p : products) {
        p.displayProduct();
        cout << "-----------------------------\n";
    }
}

double Cart::calculateSubtotal() const {

    double subtotal = 0;

    for (const auto &p : products) {
        subtotal += p.getTotalPrice();
    }

    return subtotal;
}

double Cart::calculateDiscount(double subtotal) const {

    if (subtotal > 1000) {
        return subtotal * 0.10;
    }

    return 0;
}

double Cart::calculateFinalTotal() const {

    double subtotal = calculateSubtotal();
    double discount = calculateDiscount(subtotal);

    return subtotal - discount;
}

void Cart::displayBillSummary() const {

    if (products.empty()) {
        cout << "\nCart is empty.\n";
        return;
    }

    double subtotal = calculateSubtotal();
    double discount = calculateDiscount(subtotal);
    double finalTotal = calculateFinalTotal();

    cout << "\n========== BILL SUMMARY ==========\n";

    displayCart();

    cout << "\nSubtotal: " << subtotal << endl;
    cout << "Discount: " << discount << endl;
    cout << "Final Total: " << finalTotal << endl;
}
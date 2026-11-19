#include <iostream>
#include <string>

class Cart {
    std::string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;
public:
    Cart& add(const std::string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double sum = 0;
        for (int i = 0; i < n; ++i) sum += prices[i];
        return sum * (100.0 - discount) / 100.0;
    }
};

Cart* findHighestCart(Cart* carts[], int count) {
    if (count <= 0) return nullptr;
    Cart* highest = *(carts + 0);
    for (int i = 1; i < count; ++i) {
        if ((*(carts + i))->total() > highest->total()) {
            highest = *(carts + i);
        }
    }
    return highest;
}

int main() {
    // (a) Direct access by name
    Cart c1;
    c1.add("Milk", 50.0).add("Bread", 40.0).setDiscount(10.0);

    // (b) Through a pointer with ->
    Cart* pCart = &c1;
    pCart->add("Eggs", 60.0);

    // (c) Through a reference
    Cart& rCart = c1;
    rCart.add("Butter", 100.0);

    // (d) Dynamically with new and released with delete
    Cart* dynCart = new Cart();
    dynCart->add("Headphones", 1500.0).setDiscount(5.0);

    Cart* list[2] = { &c1, dynCart };
    Cart* best = findHighestCart(list, 2);

    std::cout << "Cart 1 Total:   " << c1.total() << '\n';
    std::cout << "Dyn Cart Total: " << dynCart->total() << '\n';
    if (best) std::cout << "Highest Total:  " << best->total() << '\n';

    delete dynCart;
    return 0;
}

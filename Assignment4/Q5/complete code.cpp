#include <iostream>
#include <string>

class Cart {
    std::string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;
public:
    // TODO 1: append item & price and return *this for chaining
    Cart& add(const std::string& item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            ++n;
        }
        return *this;
    }

    // TODO 2: store parameter into member using this-> and return *this
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

int main() {
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);
    c.add("Oil", 180);
    std::cout << c.total() << '\n'; // expected: 324
    return 0;
}

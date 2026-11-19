#include <iostream>
#include <vector>
#include <memory>

class Account {
public:
    virtual double rate() const { return 3.5; }
    virtual ~Account() { std::cout << "~Account\n"; }
};

class SeniorAccount : public Account {
    double* history = new double[100];
public:
    double rate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        std::cout << "~SeniorAccount\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Account>());
    accounts.push_back(std::make_unique<SeniorAccount>());

    for (const auto& a : accounts) {
        std::cout << "Interest Rate: " << a->rate() << "%\n";
    }
    return 0;
}

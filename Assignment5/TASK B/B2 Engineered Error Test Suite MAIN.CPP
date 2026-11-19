#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <new>

struct ResourceTracker {
    std::string label;
    explicit ResourceTracker(std::string l) : label(std::move(l)) {
        std::cout << "[Acquire " << label << "]\n";
    }
    ~ResourceTracker() {
        std::cout << "[Release " << label << "]\n";
    }
};

class ClaimError : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

double lookupPackage(const std::string& code) {
    if (code == "PKG_CATARACT") return 18000.0;
    throw std::domain_error("Unknown package code: " + code);
}

void runTest(int testCase) {
    ResourceTracker guard("Tx#" + std::to_string(testCase));
    if (testCase == 1) {
        double charge = -250.0;
        if (charge < 0) throw std::invalid_argument("Negative charge rejected");
    } else if (testCase == 2) {
        double billed = 60000.0, cover = 50000.0;
        if (billed > cover) throw ClaimError("Claim exceeds cover limit");
    } else if (testCase == 3) {
        lookupPackage("PKG_UNKNOWN");
    } else if (testCase == 4) {
        double val = std::stod("INVALID_NUMBER"); // throws std::invalid_argument
        (void)val;
    } else if (testCase == 5) {
        // Force std::bad_alloc
        std::size_t huge = static_cast<std::size_t>(-1) / sizeof(double);
        double* p = new double[huge];
        delete[] p;
    }
}

int main() {
    for (int tc = 1; tc <= 5; ++tc) {
        try {
            runTest(tc);
        } catch (const ClaimError& e) {
            std::cout << "Caught ClaimError: " << e.what() << '\n';
        } catch (const std::bad_alloc& e) {
            std::cout << "Caught std::bad_alloc: " << e.what() << '\n';
        } catch (const std::exception& e) {
            std::cout << "Caught std::exception: " << e.what() << '\n';
        } catch (...) {
            std::cout << "Caught unknown exception!\n";
        }
    }
    std::cout << "Batch completed safely without losing subsequent bills.\n";
    return 0;
}

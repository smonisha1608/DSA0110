#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>

class FleetUnit {
protected:
    std::string regNo;
    double dailyRate;
    bool rented = false;

public:
    FleetUnit(std::string reg, double rate) : regNo(std::move(reg)), dailyRate(rate) {}
    virtual ~FleetUnit() = default;

    const std::string& id() const { return regNo; }
    bool available() const { return !rented; }
    void setRented(bool state) { rented = state; }

    virtual double calculateBill(int days, double energy, int lateDays) const = 0;
    virtual std::string category() const = 0;
};

class StandardCar : public FleetUnit {
public:
    StandardCar(std::string reg, double rate) : FleetUnit(std::move(reg), rate) {}
    double calculateBill(int days, double litres, int lateDays) const override {
        return (days * dailyRate) + (litres * 102.0) + (lateDays * 500.0);
    }
    std::string category() const override { return "StandardCar"; }
};

class EVCar : public FleetUnit {
    double ratePerKWh;
public:
    EVCar(std::string reg, double rate, double kwhRate)
        : FleetUnit(std::move(reg), rate), ratePerKWh(kwhRate) {}
    double calculateBill(int days, double kwh, int lateDays) const override {
        return (days * dailyRate) + (kwh * ratePerKWh) + (lateDays * 600.0);
    }
    std::string category() const override { return "EVCar"; }
};

class RentalManager {
    std::vector<std::unique_ptr<FleetUnit>> fleet;

public:
    void addUnit(std::unique_ptr<FleetUnit> unit) {
        fleet.push_back(std::move(unit));
    }

    bool rentUnit(const std::string& regNo) {
        for (auto& u : fleet) {
            if (u->id() == regNo) {
                if (!u->available()) {
                    std::cout << "[REJECTED] " << regNo << " is already rented.\n";
                    return false;
                }
                u->setRented(true);
                std::cout << "[RENTED]   " << regNo << " (" << u->category() << ")\n";
                return true;
            }
        }
        std::cout << "[NOT FOUND] " << regNo << '\n';
        return false;
    }

    double returnUnit(const std::string& regNo, int days, double energy, int lateDays) {
        for (auto& u : fleet) {
            if (u->id() == regNo) {
                if (u->available()) {
                    std::cout << "[ERROR]    " << regNo << " was not rented.\n";
                    return -1.0;
                }
                double total = u->calculateBill(days, energy, lateDays);
                u->setRented(false);
                std::cout << "[RETURNED] " << regNo << " | Total Bill: Rs. "
                          << std::fixed << std::setprecision(2) << total << '\n';
                return total;
            }
        }
        return -1.0;
    }
};

int main() {
    RentalManager manager;
    manager.addUnit(std::make_unique<StandardCar>("TN-09-CA-1001", 1500.0));
    manager.addUnit(std::make_unique<EVCar>("TN-09-EV-2002", 2000.0, 12.0));

    manager.rentUnit("TN-09-CA-1001");
    manager.rentUnit("TN-09-CA-1001"); // Duplicate rent test
    manager.rentUnit("TN-09-EV-2002");

    manager.returnUnit("TN-09-CA-1001", 2, 15.0, 0);
    manager.returnUnit("TN-09-EV-2002", 4, 30.0, 1);
    return 0;
}

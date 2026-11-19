#include <iostream>
#include <string>
#include <iomanip>

struct Date {
    int day, month, year;
    std::string str() const {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }
};

class Vehicle {
protected:
    std::string regNo;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(std::string reg, double rate) : regNo(std::move(reg)), dailyRate(rate) {}
    virtual ~Vehicle() = default;

    std::string getRegNo() const { return regNo; }
    bool isRented() const { return rented; }
    void setRented(bool status) { rented = status; }

    virtual double computeCharge(int days, double energyUsed, int lateDays) const = 0;
    virtual void printInfo() const = 0;
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string reg, double rate) : Vehicle(std::move(reg), rate) {}
    double computeCharge(int days, double /*unused*/, int lateDays) const override {
        return (days * dailyRate) + (lateDays * 50.0);
    }
    void printInfo() const override {
        std::cout << "[Bicycle]     " << regNo << " | Rate: Rs." << dailyRate << "/day\n";
    }
};

class MotorVehicle : public Vehicle {
protected:
    double energyLevel;
    Date serviceDue;

public:
    MotorVehicle(std::string reg, double rate, double level, Date due)
        : Vehicle(std::move(reg), rate), energyLevel(level), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
    static constexpr double PETROL_RATE = 102.0;
public:
    TwoWheeler(std::string reg, double rate, double level, Date due)
        : MotorVehicle(std::move(reg), rate, level, due) {}

    double computeCharge(int days, double litresUsed, int lateDays) const override {
        return (days * dailyRate) + (litresUsed * PETROL_RATE) + (lateDays * 150.0);
    }
    void printInfo() const override {
        std::cout << "[TwoWheeler]  " << regNo << " | Service Due: " << serviceDue.str() << '\n';
    }
};

class Car : public MotorVehicle {
protected:
    int seatingCapacity;
    static constexpr double FUEL_RATE = 102.0;

public:
    Car(std::string reg, double rate, double level, Date due, int seats)
        : MotorVehicle(std::move(reg), rate, level, due), seatingCapacity(seats) {}

    double computeCharge(int days, double litresUsed, int lateDays) const override {
        return (days * dailyRate) + (litresUsed * FUEL_RATE) + (lateDays * 500.0);
    }
    void printInfo() const override {
        std::cout << "[Car]         " << regNo << " | Seats: " << seatingCapacity << '\n';
    }
};

class ElectricCar : public Car {
    double batteryKWh;
    double ratePerKWh;

public:
    ElectricCar(std::string reg, double rate, double level, Date due,
                int seats, double battery, double kwhRate)
        : Car(std::move(reg), rate, level, due, seats),
          batteryKWh(battery), ratePerKWh(kwhRate) {}

    double computeCharge(int days, double kwhUsed, int lateDays) const override {
        return (days * dailyRate) + (kwhUsed * ratePerKWh) + (lateDays * 600.0);
    }
    void printInfo() const override {
        std::cout << "[ElectricCar] " << regNo << " | Battery: " << batteryKWh << " kWh\n";
    }
};

class ElectricBus : public ElectricCar {
public:
    ElectricBus(std::string reg, double rate, double level, Date due,
                int seats, double battery, double kwhRate)
        : ElectricCar(std::move(reg), rate, level, due, seats, battery, kwhRate) {}

    double computeCharge(int days, double kwhUsed, int lateDays) const override {
        return ElectricCar::computeCharge(days, kwhUsed, lateDays) + (lateDays * 1000.0);
    }
    void printInfo() const override {
        std::cout << "[ElectricBus] " << regNo << " | Heavy EV Fleet\n";
    }
};

int main() {
    const int N = 5;
    Vehicle* fleet[N] = {
        new Bicycle("CYC-01", 100.0),
        new TwoWheeler("TN-01-AB-1111", 400.0, 80.0, {15, 12, 2026}),
        new Car("TN-01-CD-2222", 1500.0, 90.0, {20, 1, 2027}, 5),
        new ElectricCar("TN-01-EV-3333", 2000.0, 95.0, {10, 3, 2027}, 5, 60.0, 12.0),
        new ElectricBus("TN-01-EB-4444", 5000.0, 100.0, {5, 4, 2027}, 40, 250.0, 15.0)
    };

    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < N; ++i) {
        fleet[i]->printInfo();
        fleet[i]->setRented(true);
        double bill = fleet[i]->computeCharge(3, 10.0, 1);
        fleet[i]->setRented(false);
        std::cout << "  -> 3-Day Rental + 10 Units + 1 Late Day = Rs. " << bill << "\n\n";
    }

    for (int i = 0; i < N; ++i) delete fleet[i];
    return 0;
}

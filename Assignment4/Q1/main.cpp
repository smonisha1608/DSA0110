#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Staff {
protected:
    std::string name;
    int id;

public:
    Staff(std::string name, int id) : name(std::move(name)), id(id) {}
    virtual ~Staff() = default;
    virtual double pay() const = 0;
    std::string getName() const { return name; }
};

class RegularStaff : public Staff {
protected:
    double basic;
    static constexpr double DA_RATE = 0.42;

public:
    RegularStaff(std::string name, int id, double basic)
        : Staff(std::move(name), id), basic(basic) {}
    double pay() const override { return basic + (basic * DA_RATE); }
};

class Professor : public RegularStaff {
private:
    double research;

public:
    Professor(std::string name, int id, double basic, double research)
        : RegularStaff(std::move(name), id, basic), research(research) {}
    double pay() const override { return RegularStaff::pay() + research; }
};

class LabAssistant : public RegularStaff {
public:
    LabAssistant(std::string name, int id, double basic)
        : RegularStaff(std::move(name), id, basic) {}
};

class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(std::string name, int id, double hours, double rate)
        : Staff(std::move(name), id), hours(hours), rate(rate) {}
    double pay() const override { return hours * rate; }
};

int main() {
    std::vector<std::unique_ptr<Staff>> payroll;
    payroll.push_back(std::make_unique<Professor>("Dr. Rao", 101, 80000, 15000));
    payroll.push_back(std::make_unique<LabAssistant>("Kiran", 102, 35000));
    payroll.push_back(std::make_unique<GuestFaculty>("Meera", 103, 40, 1200));

    for (const auto& s : payroll) {
        std::cout << s->getName() << " Pay: " << s->pay() << '\n';
    }
    return 0;
}

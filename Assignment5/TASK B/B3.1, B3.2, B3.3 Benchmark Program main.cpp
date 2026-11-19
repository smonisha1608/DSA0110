#include <iostream>
#include <vector>
#include <memory>
#include <variant>
#include <chrono>
#include <iomanip>
#include <stdexcept>

// (a) Virtual Hierarchy
struct VBill {
    virtual ~VBill() = default;
    virtual double total() const = 0;
};
struct VOP : VBill {
    double c, t;
    VOP(double c, double t) : c(c), t(t) {}
    double total() const override { return c + t; }
};
struct VIP : VBill {
    int d; double r, s;
    VIP(int d, double r, double s) : d(d), r(r), s(s) {}
    double total() const override { return d * r + s; }
};

// (b) Single Struct + switch
enum class BType { OP, IP };
struct SBill {
    BType type;
    double c, t;
    int d; double r, s;
    double total() const {
        switch (type) {
            case BType::OP: return c + t;
            case BType::IP: return d * r + s;
        }
        return 0.0;
    }
};

// (c) Alternative: std::variant + std::visit
struct VarOP { double c, t; double total() const { return c + t; } };
struct VarIP { int d; double r, s; double total() const { return d * r + s; } };
using VarBill = std::variant<VarOP, VarIP>;

using Clock = std::chrono::high_resolution_clock;

void runDispatchBench(std::size_t N) {
    std::vector<std::unique_ptr<VBill>> vBills;
    std::vector<SBill> sBills;
    std::vector<VarBill> varBills;
    vBills.reserve(N); sBills.reserve(N); varBills.reserve(N);

    for (std::size_t i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            vBills.push_back(std::make_unique<VOP>(500, 1200));
            sBills.push_back({BType::OP, 500, 1200, 0, 0, 0});
            varBills.emplace_back(VarOP{500, 1200});
        } else {
            vBills.push_back(std::make_unique<VIP>(3, 2500, 40000));
            sBills.push_back({BType::IP, 0, 0, 3, 2500, 40000});
            varBills.emplace_back(VarIP{3, 2500, 40000});
        }
    }

    auto t1 = Clock::now();
    volatile double sumV = 0;
    for (const auto& b : vBills) sumV += b->total();
    auto t2 = Clock::now();

    volatile double sumS = 0;
    for (const auto& b : sBills) sumS += b.total();
    auto t3 = Clock::now();

    volatile double sumVar = 0;
    for (const auto& b : varBills) {
        sumVar += std::visit([](const auto& x) { return x.total(); }, b);
    }
    auto t4 = Clock::now();

    double msV = std::chrono::duration<double, std::milli>(t2 - t1).count();
    double msS = std::chrono::duration<double, std::milli>(t3 - t2).count();
    double msVar = std::chrono::duration<double, std::milli>(t4 - t3).count();

    std::cout << "N=" << std::setw(8) << N
              << " | Virtual: " << std::setw(6) << msV << " ms"
              << " | Switch: " << std::setw(6) << msS << " ms"
              << " | Variant: " << std::setw(6) << msVar << " ms\n";
}

double validateReturnCode(double amt, int& err) {
    if (amt < 0) { err = 1; return 0.0; }
    err = 0; return amt;
}
double validateException(double amt) {
    if (amt < 0) throw std::invalid_argument("neg");
    return amt;
}

void runExceptionBench(int invalidPct) {
    const int N = 1'000'000;
    std::vector<double> data(N, 100.0);
    for (int i = 0; i < N; ++i) {
        if ((i % 100) < invalidPct) data[i] = -10.0;
    }

    auto t1 = Clock::now();
    volatile double ok1 = 0;
    for (double x : data) {
        int err = 0;
        double r = validateReturnCode(x, err);
        if (err == 0) ok1 += r;
    }
    auto t2 = Clock::now();

    volatile double ok2 = 0;
    for (double x : data) {
        try { ok2 += validateException(x); }
        catch (const std::invalid_argument&) {}
    }
    auto t3 = Clock::now();

    double msRC = std::chrono::duration<double, std::milli>(t2 - t1).count();
    double msEx = std::chrono::duration<double, std::milli>(t3 - t2).count();
    std::cout << "Invalid=" << std::setw(2) << invalidPct << "%"
              << " | ReturnCode: " << std::setw(6) << msRC << " ms"
              << " | Exceptions: " << std::setw(6) << msEx << " ms\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(3);
    for (std::size_t n : {10UL, 1000UL, 1'000'000UL, 10'000'000UL}) runDispatchBench(n);
    std::cout << "---\n";
    for (int pct : {0, 1, 50}) runExceptionBench(pct);
    return 0;
}

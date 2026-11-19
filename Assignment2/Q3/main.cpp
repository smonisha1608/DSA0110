#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

void charge(int grams, bool express = false, bool insured = false)
{
    double amount = grams * 0.05;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    cout << "Integer grams charge: " << amount << '\n';
}

void charge(double kilograms, bool express = false, bool insured = false)
{
    double amount = kilograms * 50;

    if (express)
        amount += 20;

    if (insured)
        amount += 10;

    cout << "Double kilograms charge: " << amount << '\n';
}

void charge(const Parcel& parcel)
{
    double amount = parcel.weight * 50;

    if (parcel.express)
        amount += 20;

    if (parcel.insured)
        amount += 10;

    cout << "Parcel charge: " << amount << '\n';
}

int main()
{
    Parcel p = {3.0, true, true};

    charge(2);
    charge(2.0f);
    charge(500);
    charge(2.5);
    charge(1000, true);
    charge(p);

    return 0;
}

#include <iostream>

class Time
{
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    int difference = first - second;

    return difference < 0 ? -difference : difference;
}

bool earlier(const Time& a, const Time& b)
{
    if (a.h != b.h)
        return a.h < b.h;

    return a.m < b.m;
}

int main()
{
    Time departure(9, 45), arrival(13, 10);

    std::cout << minutesBetween(departure, arrival) << ' '
              << std::boolalpha
              << earlier(arrival, departure) << '\n';
}

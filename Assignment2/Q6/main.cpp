#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b)
{
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;

    int difference = first - second;

    return difference < 0 ? -difference : difference;
}

inline bool earlier(const Time& a, const Time& b)
{
    if (a.h != b.h)
        return a.h < b.h;

    return a.m < b.m;
}

int normalMinutesBetween(int a, int b)
{
    int difference = a - b;
    return difference < 0 ? -difference : difference;
}

inline int inlineMinutesBetween(int a, int b)
{
    int difference = a - b;
    return difference < 0 ? -difference : difference;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);
    Time same(12, 30);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    cout << "Same time difference: "
         << minutesBetween(same, same) << '\n';

    cout << "Before noon comparison: "
         << earlier(Time(11, 50), Time(12, 10)) << '\n';

    const int iterations = 10000000;
    volatile long long result = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
        result = result + normalMinutesBetween(i % 1440, (i + 1) % 1440);

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++)
        result = result + inlineMinutesBetween(i % 1440, (i + 1) % 1440);

    auto end2 = high_resolution_clock::now();

    cout << "Non-inline time: "
         << duration_cast<milliseconds>(end1 - start1).count()
         << " ms\n";

    cout << "Inline time: "
         << duration_cast<milliseconds>(end2 - start2).count()
         << " ms\n";

    cout << "Check value: " << result << '\n';

    return 0;
}

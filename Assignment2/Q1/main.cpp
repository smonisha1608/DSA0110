
#include <iostream>
using namespace std;

void concessionByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << '\n';
}

void concessionByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

void concessionByPointer(long long* fee, int percent)
{
    *fee -= (*fee) * percent / 100;
}

int main()
{
    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    concessionByValue(fee1, 10);
    cout << "After call by value: " << fee1 << '\n';

    concessionByReference(fee2, 15);
    cout << "After call by reference: " << fee2 << '\n';

    concessionByPointer(&fee3, 25);
    cout << "After call by pointer: " << fee3 << '\n';

    return 0;
}

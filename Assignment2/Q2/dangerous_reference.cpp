#include <iostream>
using namespace std;

int& dangerousReference()
{
    int value = 100;
    return value;
}

int main()
{
    int& result = dangerousReference();
    cout << result << '\n';

    return 0;
}

#include <iostream>
using namespace std;

class ShiftAccount
{
private:
    int transactions[10];
    int count;

public:
    ShiftAccount() : count(0) {}

    void add(int value)
    {
        if (count < 10)
        {
            transactions[count++] = value;
        }
        else
        {
            for (int i = 1; i < 10; i++)
                transactions[i - 1] = transactions[i];

            transactions[9] = value;
        }
    }

    void display() const
    {
        for (int i = 0; i < count; i++)
            cout << transactions[i] << ' ';

        cout << '\n';
    }
};

class CircularAccount
{
private:
    int transactions[10];
    int start;
    int count;

public:
    CircularAccount() : start(0), count(0) {}

    void add(int value)
    {
        int position = (start + count) % 10;

        if (count < 10)
        {
            transactions[position] = value;
            count++;
        }
        else
        {
            transactions[start] = value;
            start = (start + 1) % 10;
        }
    }

    void display() const
    {
        for (int i = 0; i < count; i++)
        {
            int position = (start + i) % 10;
            cout << transactions[position] << ' ';
        }

        cout << '\n';
    }
};

int main()
{
    ShiftAccount original;
    CircularAccount redesigned;

    for (int i = 1; i <= 15; i++)
    {
        original.add(i * 100);
        redesigned.add(i * 100);
    }

    cout << "Original shifting array:\n";
    original.display();

    cout << "Redesigned circular buffer:\n";
    redesigned.display();

    return 0;
}

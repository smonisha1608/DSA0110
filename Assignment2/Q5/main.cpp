#include <iostream>
#include <string>
using namespace std;

class TicketOffice
{
private:
    int issued;
    int capacity;

public:
    TicketOffice(int seats) : issued(0), capacity(seats) {}

    int issueSeat()
    {
        if (issued < capacity)
            return ++issued;

        return 0;
    }

    int count() const
    {
        return issued;
    }
};

class BusTicket
{
private:
    int seat;
    string name;

public:
    BusTicket(const string& passenger, TicketOffice& office)
    {
        name = passenger;
        seat = office.issueSeat();
    }

    void print() const
    {
        cout << name << ": ";

        if (seat == 0)
            cout << "Waiting\n";
        else
            cout << "Seat " << seat << '\n';
    }
};

int main()
{
    TicketOffice busA(2);
    TicketOffice busB(2);

    BusTicket a1("Asha", busA);
    BusTicket a2("Bala", busA);
    BusTicket a3("Chitra", busA);

    BusTicket b1("Dev", busB);
    BusTicket b2("Esha", busB);

    cout << "Bus A:\n";
    a1.print();
    a2.print();
    a3.print();

    cout << "Bus A issued: " << busA.count() << '\n';

    cout << "\nBus B:\n";
    b1.print();
    b2.print();

    cout << "Bus B issued: " << busB.count() << '\n';

    return 0;
}

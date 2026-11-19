#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount)
    {
        if (count < 10)
        {
            transactions[count] = amount;
            count++;
        }
        else
        {
            for (int i = 1; i < 10; i++)
                transactions[i - 1] = transactions[i];

            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int number, double initialBalance)
    {
        accountNumber = number;
        balance = initialBalance;
        count = 0;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit\n";
            return;
        }

        balance += amount;
        addTransaction(amount);
    }

    void withdraw(double amount);

    void miniStatement()
    {
        cout << "\nAccount Number: " << accountNumber << '\n';
        cout << "Balance: " << balance << '\n';
        cout << "Last transactions:\n";

        for (int i = 0; i < count; i++)
            cout << transactions[i] << '\n';
    }
};

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal\n";
        return;
    }

    balance -= amount;
    addTransaction(-amount);
}

int main()
{
    SavingsAccount account(1001, 5000);

    account.deposit(500);
    account.withdraw(200);
    account.deposit(1000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}

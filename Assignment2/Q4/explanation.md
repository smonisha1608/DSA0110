Q4 – SPECIFYING A CLASS WITH AN ARRAY INSIDE IT

Objective:
To create a SavingsAccount class that stores the account details,
balance and last ten transactions.

Private members:
accountNumber – stores the account number.
balance – stores the current account balance.
transactions[10] – stores the last ten transactions.
count – stores the number of available transaction entries.

Public functions:
deposit() – adds money to the account.
withdraw() – removes money from the account.
miniStatement() – displays account details and transactions.

Design:
The array is private to protect the account data.
Member functions control all modifications to the balance and
transaction history.

Some member functions are defined inside the class.
withdraw() is defined outside the class using the scope resolution
operator.

When the 11th transaction arrives:
The shifting approach removes the oldest transaction by shifting
the remaining nine entries.
The new transaction is placed at the final position.

Alternative:
A circular buffer stores a starting index and a count.
When full, the oldest entry is overwritten without shifting all
the other entries.

Complexity:
Shifting array insertion when full: O(k), where k is the number
of stored transactions.
Circular buffer insertion: O(1).
Space for the fixed array: O(10), which is O(1) for a fixed capacity.

Design decision:
For a requirement of 50 transactions, a circular buffer is preferable
because it avoids shifting elements whenever a new transaction arrives.

Conclusion:
The class protects its data using private access and provides controlled
operations through public member functions.

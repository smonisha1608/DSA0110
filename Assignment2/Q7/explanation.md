Q7 – DIAGNOSE, REDESIGN AND VALIDATE

A. Diagnose the limitation

The original SavingsAccount uses a fixed array of ten transactions.
When the array becomes full, every new transaction requires shifting
the remaining nine entries.

This creates unnecessary element movement as the number of new
transactions increases.

B. Design objective

Redesign the transaction storage so that adding a transaction
does not require shifting all existing transactions.

C. Revised design

The redesigned class uses a circular buffer.

It stores:
1. An array of ten transactions.
2. A start index.
3. A count of stored transactions.

When the buffer is full, the oldest transaction is overwritten.
The start index moves forward using modulo arithmetic.

Pseudocode:

position = (start + count) % capacity

If count < capacity:
    Store the new transaction at position.
    Increase count.

Otherwise:
    Replace the oldest transaction.
    Move start to the next position.

D. Prediction

The shifting design requires O(k) work when full.
The circular buffer requires O(1) work to add a transaction.

Both designs should display the same last ten transactions.

E. Implementation and validation

The program inserts fifteen transactions into both designs.

Expected output:

Original shifting array:
600 700 800 900 1000 1100 1200 1300 1400 1500

Redesigned circular buffer:
600 700 800 900 1000 1100 1200 1300 1400 1500

Both designs retain the latest ten transactions.

F. Final evaluation

The circular buffer achieves the objective because it avoids
shifting the stored elements.

Original shifting design:
Insertion when full: O(k)
Space: O(10)

Circular buffer:
Insertion: O(1)
Space: O(10)

Trade-off:
The circular buffer requires additional index management.
The shifting design is simpler and may be suitable when transactions
are added infrequently.

Conclusion:
The circular buffer is preferable for frequent transaction updates
because it reduces the work required for each insertion while
preserving the latest ten transactions.

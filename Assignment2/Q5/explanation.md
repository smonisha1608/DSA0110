Q5 – STATIC MEMBERS AND ARRAYS OF OBJECTS

Objective:
To use static members to maintain a shared ticket count and assign
seats to BusTicket objects.

Static data member:
The issued variable belongs to the entire class rather than an
individual object.

Static member function:
count() returns the shared number of issued seats.
A static function cannot directly access this or non-static members
because it is not called for one particular object.

Definition:
The static data member is defined outside the class:
int BusTicket::issued = 0;

Array of objects:
BusTicket trip[4] creates four BusTicket objects.
Each constructor runs once, in array order.

Token prediction:
The static counter starts at 100.
Three array objects and one extra object are created.
The IDs become 101, 102, 103 and 104.
The issued function returns 4.

Expected output:
101 103 104 4

BusTicket:
The capacity is three.
The first three objects receive seats.
The fourth object remains on the waiting list.

Expected output:
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3

Function called twice:
A static counter remains shared between calls.
It does not automatically reset when a function returns.
Therefore, a second call continues from the previous count.

Alternative concept:
A global variable can hold the count, but it is less encapsulated.
A separate TicketOffice object can manage each bus independently.

Complexity:
Seat assignment: O(1).
Counting: O(1).
One shared counter requires O(1) additional space.

Design decision:
A static counter is appropriate when one shared capacity is required.
A TicketOffice object is more suitable when multiple buses must
maintain independent seat counts.

Conclusion:
Static members store class-wide information, while arrays of objects
allow multiple tickets to be created and initialised.

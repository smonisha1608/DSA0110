Q6 – FRIEND FUNCTIONS AND INLINE FUNCTIONS

Objective:
To calculate the difference between two times and compare their
order using friend functions.

Friend functions:
A friend function is not a member of the class.
However, it can access private members when declared as a friend.

minutesBetween():
Converts both times into minutes and calculates the absolute
difference.

earlier():
Compares the hours first. If the hours are equal, it compares
the minutes.

Correctness:
Departure: 09:45
Arrival: 13:10
Difference: 205 minutes
Arrival is not earlier than departure.

Expected output:
205 false

Additional tests:
The same time compared with itself must produce a difference of 0.
11:50 must be earlier than 12:10.

Inline:
The inline keyword requests that the compiler consider expanding
a function at the call location. It does not guarantee that this
will happen.

Measurement:
The program measures ten million calls for inline and non-inline
functions.

Compile separately using -O0 and -O2.
Record the actual execution times from your computer.

Alternative concepts:
1. Member functions:
   a.minutesTo(b)
   a.isEarlier(b)

2. Public getter functions:
   getHour()
   getMinute()

Member functions can access their own object's private data.
Getter functions preserve private access but require extra calls
unless optimised.

Complexity:
Time comparison: O(1).
Extra space: O(1).

Design decision:
Friend functions are suitable when an operation treats two objects
equally and needs access to their private data.
Public getters or member functions may provide tighter encapsulation
depending on the application.

Conclusion:
The friend design preserves private data while allowing two Time
objects to be compared. Inline functions may help small functions,
but actual performance must be measured.

Q3 – DEFAULT ARGUMENTS AND FUNCTION OVERLOADING

Objective:
To design courier charge functions using default arguments and
function overloading without ambiguous calls.

Original problem:
The original declarations contain overlapping overloads:
charge(double weight)
charge(double weight, bool express)
charge(double weight, bool express = false, bool insured = false)

A call such as charge(2) can match more than one overload.
This creates ambiguity.

Redesign:
Use three distinct input types:
1. int for weight in grams.
2. double for weight in kilograms.
3. Parcel structure for parcel details.

Predictions before execution:

Call                 Selected function
charge(2)            int overload
charge(2.0f)         double overload
charge(500)          int overload
charge(2.5)          double overload
charge(1000, true)   int overload
charge(p)            Parcel overload

Explanation:
An exact match is preferred over a promotion or conversion.
The float argument in charge(2.0f) is promoted to double.
The integer argument in charge(2) exactly matches int.

Default arguments:
Default arguments allow common calls to omit optional parameters.
They must be supplied from right to left.

For example:
void charge(int grams, bool express = false, bool insured = false);

The caller can provide only grams, grams and express, or all three
arguments.

Alternative concept:
A single Parcel structure can hold weight, express and insurance
details. This reduces the number of overloaded functions and makes
adding new options easier.

Complexity:
Overload resolution happens at compile time and has no runtime
execution cost.
The charge calculation takes O(1) time.
The Parcel object is passed by const reference, avoiding an
unnecessary object copy.

Conclusion:
Overloading is suitable for different input types. Default arguments
make common calls shorter. The redesigned signatures avoid ambiguity.

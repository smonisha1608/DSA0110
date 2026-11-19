
# Q1 – Call by Value, Reference and Pointer

## 1. Objective

To demonstrate call by value, call by reference and
call by pointer using a hostel fee concession system.

## 2. Algorithm

1. Initialize three hostel fees with 45000.
2. Apply 10% concession using call by value.
3. Apply 15% concession using call by reference.
4. Apply 25% concession using call by pointer.
5. Display all three results.
6. Execute the output-prediction program.
7. Verify the predicted and actual outputs.

## 3. Pseudocode

START

Initialize fee1, fee2 and fee3 as 45000.

Apply concession using call by value to fee1.

Apply concession using call by reference to fee2.

Apply concession using call by pointer to fee3.

Display all fees.

STOP.

## 4. Output Prediction

Predicted output:

1 12 13
1 100
16 13 6

## 5. Explanation

Call by Value:
A copy of the original variable is passed.
Changes affect only the local copy.

Call by Reference:
The function receives a reference to the original variable.
Changes directly affect the caller's variable.

Call by Pointer:
The address of the variable is passed.
The original value is modified using the dereference operator.

In the prediction program, a remains unchanged because
it is passed by value. Variables b and c change because
they are passed by reference and pointer.

The bigger() function returns a reference to the larger
variable. Therefore, assigning 100 modifies that variable.

Default Arguments:

show(1) uses y=5 and z=10.
show(1,2) uses z=10.
show(1,2,3) uses all supplied arguments.

## 6. Complete the Code Explanation

Call by value does not modify the original hostel fee
because it operates on a separate copy.

Call by reference modifies the original hostel fee.

Therefore, the final fee becomes 40500.

## 7. Inquiry

A parameter passed by value stores a separate copy.

A reference parameter refers to the original variable.

A pointer parameter stores the memory address of the
original variable.

A const reference should be used when a function needs
to read a variable without copying or modifying it.

Example:

void display(const int& value);

## 8. Design Decision

Call by reference is suitable when the hostel office
needs to update the student's existing fee.

It avoids creating another fee variable.

Returning a new fee is also suitable when the original
fee must be preserved.

## 9. Alternative Concept

The concession function can return the updated fee.

long long applyConcession(long long fee, int percent)
{
    fee -= fee * percent / 100;
    return fee;
}

Calling:

hostelFee = applyConcession(hostelFee, 10);

## 10. Test Cases

| Initial Fee | Concession | Expected Fee |
|-------------|------------|--------------|
| 45000 | 10% | 40500 |
| 45000 | 15% | 38250 |
| 45000 | 25% | 33750 |
| 10000 | 0% | 10000 |

## 11. Complexity Analysis

| Method | Time Complexity | Additional Space |
|--------|-----------------|------------------|
| Call by Value | O(1) | O(1) |
| Call by Reference | O(1) | O(1) |
| Call by Pointer | O(1) | O(1) |
| Return by Value | O(1) | O(1) |

For a large Student object, call by value copies the
entire object, requiring space proportional to its size.

Reference and const reference avoid copying the object
and require O(1) additional parameter space.

## 12. Conclusion

Call by value protects the original variable from
modification. Call by reference and call by pointer
allow modification of the original variable.

The appropriate method depends on the requirement
of the application.

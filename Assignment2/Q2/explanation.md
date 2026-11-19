Q2 – RETURN BY REFERENCE AND ITS DANGERS

Objective:
To understand how a function can return a reference to an existing array
element and how returning a reference to a local variable creates a
dangling reference.

Algorithm:
1. Store student marks in an integer array.
2. Find the index containing the highest mark.
3. Return that element using a reference.
4. Increase the highest mark by 2.
5. Compare reference, const reference, copy and index approaches.

Expected observations:
Original highest mark: 92
After moderation: 94
Const reference: 94
Returned copy: 94
Highest mark index: 2
After index modification: 95

Explanation:
A returned reference refers to the original array element. Therefore,
modifying it also modifies the original array.

A const reference allows reading but prevents modification through
that reference.

Returning a copy creates a separate value. Modifying the copy does not
change the original array.

Returning an index allows the caller to access the element using
marks[index]. A pointer can also refer to the element, but it must
remain valid.

Dangerous reference:
The dangerousReference() function returns a reference to a local
variable. The variable is destroyed when the function ends.
The returned reference is therefore dangling. Using it causes
undefined behaviour.

Vector condition:
A vector may reallocate its storage when it grows. References and
pointers to its elements can become invalid after reallocation.
Access the element again through the vector after growth.

Complexity:
Finding the highest mark: O(n)
Returning a reference: O(1)
Returning a copy: O(1) for an integer
Returning an index: O(1)
Extra space: O(1)

Conclusion:
Returning a reference is useful when the caller must modify an existing
element. Returning a const reference is safer for read-only access.
Returning an index is useful when the caller needs to access the element
again and can ensure the container has not changed.

# Task 03 – Constructors in Derived Classes and Member Classes

## Construction & Destruction Order Rule
1. **Virtual base classes** (depth-first, left-to-right).
2. **Non-virtual base classes** (declaration order).
3. **Member objects** (declaration order inside the class).
4. **Derived constructor body**.
5. **Destructors** execute in exact reverse order.

## Why Most-Derived Calls Virtual Base Constructor
Because `Person` is shared by `Student` and `Staff`, C++ requires the most-derived class (`TeachingAssistant`) to invoke `Person(...)` directly so the shared base is initialized once rather than ambiguously twice.

## Experiment & Complete-the-Code Findings
- Removing `virtual` doubles `Person` and `Address` constructions/destructions and increases `sizeof(TeachingAssistant)` by an extra `Person` sub-object (~32–40 bytes).
- Swapping initializer list order triggers `-Wreorder` under `-Wall` because C++ always initializes bases and members in class declaration order.
- Storing `Address* home = new Address(...)` adds $O(1)$ heap allocation overhead, 8 bytes pointer space, and requires the **Rule of Three** (Constructor, Deep-Copy Constructor, Destructor).

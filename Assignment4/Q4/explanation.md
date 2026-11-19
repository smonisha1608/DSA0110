# Task 04 – Pointers to Derived Classes: Forensics

## 4.1 Defects Located
1. **Static Binding on `rate()`:** `Account::rate()` lacked `virtual`, so `a->rate()` always called `Account::rate()` (3.5%).
2. **Memory Leak on `delete a`:** `Account::~Account()` was non-virtual, skipping `~SeniorAccount()` and leaking `double[100]` (800 bytes).
3. **Object Slicing:** `Account copy = SeniorAccount();` sliced off the derived `SeniorAccount` part when copying by value into a base object.

## 4.2 AddressSanitizer Evidence
Compiling the defective code with `-fsanitize=address` reports:
`Direct leak of 800 byte(s) in 1 object(s) allocated from operator new[](unsigned long) in SeniorAccount::SeniorAccount()`.

## 4.4 Prevention Rules
- Always declare `virtual ~Base() = default;` in polymorphic base classes.
- Always annotate overrides with `override`.
- Store polymorphic objects via smart pointers (`std::unique_ptr<Base>`) instead of by value.

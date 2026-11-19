# Task 05 – Pointers to Objects and the `this` Pointer

## Comparison of Four Access Modes
| Mode | Safety | Lifetime | Best Use Case |
| :--- | :--- | :--- | :--- |
| Direct Object (`Cart c`) | Highest | Automatic (scope) | Default local variables |
| Raw Pointer (`Cart* p`) | Low (nullable/dangling) | Non-owning | Optional links / pointer arrays |
| Reference (`Cart& r`) | High (never null) | Non-owning alias | Function parameters & chaining |
| Dynamic (`new`/`delete`) | Lowest (leak/double-free) | Manual heap | Outliving scope (prefer `unique_ptr`) |

## Complete the Code Analysis
If `add()` returns `Cart` by value instead of `Cart&`:
- `.add("Dal", 120)` and `.setDiscount(10)` mutate a **temporary copy** that is destroyed at `;`.
- `c` only retains `"Rice"` (60) and `"Oil"` (180) with `discount = 0`, printing **`240`** instead of `324`.

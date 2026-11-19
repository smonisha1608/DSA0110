# Task 02 – From Requirement to Hierarchy

## 2.1 Relationships
- `Student` is-a `Person` & `Staff` is-a `Person` -> **Hierarchical Inheritance**
- `TeachingAssistant` is-a `Student` AND `Staff` -> **Multiple / Diamond Inheritance**
- `ResearchScholar` is-a `Student` -> **Multilevel Inheritance**
- `ResearchScholar` has-a `Fellowship` -> **Composition**

## 2.2 Diamond Resolution
Without `virtual` inheritance, `TeachingAssistant` contains two `Person` sub-objects, causing member ambiguity (`ta.name` fails to compile). Declaring `class Student : virtual public Person` and `class Staff : virtual public Person` merges them into a single shared `Person` sub-object.

## 2.4 Access Table
| Visibility in `Person` | `public` Inheritance | `protected` Inheritance | `private` Inheritance |
| :--- | :--- | :--- | :--- |
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | Inaccessible | Inaccessible | Inaccessible |

## Predict the Output Analysis
- **With `virtual`:** `Person Student Staff TA ` (`Person` constructed once first).
- **Without `virtual`:** `Person Student Person Staff TA ` (`Person` constructed twice—once via `Student`, once via `Staff`).
- **Alternative (Composition):** Doubles `Person` memory footprint (+64–72 bytes) and creates two independent `name` copies that can fall out of sync.

# Task 06 – Design Challenge: Vehicle Rental Fleet

## Design Decisions
- **Hierarchy:** `Vehicle` (abstract) -> `Bicycle` & `MotorVehicle` (with `Date serviceDue` composition) -> `TwoWheeler` & `Car` -> `ElectricCar` -> `ElectricBus`.
- **Polymorphism:** Pure virtual `computeCharge(...)` and `printInfo()` with `virtual ~Vehicle() = default;` allow storing heterogeneous vehicles in a single `Vehicle* fleet[]` array.
- **Complexity vs. Single-Class Switch:** Both achieve $O(1)$ dispatch, but the hierarchy modifies **0 existing classes** when adding `ElectricBus` and avoids wasting ~40 bytes of unused EV/fuel fields on every `Bicycle`.

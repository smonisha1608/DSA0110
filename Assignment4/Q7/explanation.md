# Task 07 – Integrated Rental Reservation & Billing System

Combines smart-pointer polymorphic ownership (`std::vector<std::unique_ptr<FleetUnit>>`), encapsulation of rental state transitions (`rentUnit` / `returnUnit`), and runtime dispatch for fuel vs. EV billing without manual `new`/`delete` or object slicing.

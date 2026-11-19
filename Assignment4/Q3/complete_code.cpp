#include <iostream>
#include <string>

class Address {
    std::string city;
    int pin;
public:
    Address(const std::string& c, int p) : city(c), pin(p) {}
    void show() const { std::cout << city << '-' << pin; }
};

class Person {
    std::string name;
    int age;
public:
    Person(const std::string& n, int a) : name(n), age(a) {}
    void show() const { std::cout << name << " (" << age << ")"; }
};

class Student : public Person {
    long long regNo;
    Address home;
public:
    // TODO 1: Complete member-initializer list
    Student(const std::string& n, int a, long long r, const std::string& c, int p)
        : Person(n, a), regNo(r), home(c, p) {}

    void show() const {
        Person::show();
        std::cout << " | " << regNo << " | ";
        home.show();
        std::cout << '\n';
    }
};

int main() {
    Student s("Priya", 19, 192524152, "Chennai", 600001);
    s.show();
    return 0;
}

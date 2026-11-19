#include <iostream>
#include <string>

class Address {
    std::string city;
public:
    Address(std::string c) : city(std::move(c)) { std::cout << "Address "; }
    ~Address() { std::cout << "~Address "; }
};

class Course {
    std::string code;
public:
    Course(std::string c) : code(std::move(c)) { std::cout << "Course "; }
    ~Course() { std::cout << "~Course "; }
};

class Person {
protected:
    std::string name;
    Address addr;
public:
    Person(std::string n, std::string city)
        : name(std::move(n)), addr(std::move(city)) { std::cout << "Person "; }
    virtual ~Person() { std::cout << "~Person "; }
};

class Student : virtual public Person {
protected:
    Course course;
public:
    Student(std::string n, std::string city, std::string cCode)
        : Person(n, city), course(std::move(cCode)) { std::cout << "Student "; }
    ~Student() override { std::cout << "~Student "; }
};

class Staff : virtual public Person {
protected:
    std::string dept;
public:
    Staff(std::string n, std::string city, std::string d)
        : Person(n, city), dept(std::move(d)) { std::cout << "Staff "; }
    ~Staff() override { std::cout << "~Staff "; }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(std::string n, std::string city, std::string cCode, std::string d)
        : Person(n, city),
          Student(n, city, std::move(cCode)),
          Staff(n, city, std::move(d)) {
        std::cout << "TA ";
    }
    ~TeachingAssistant() override { std::cout << "~TA "; }
};

int main() {
    std::cout << "sizeof(TeachingAssistant): " << sizeof(TeachingAssistant) << " bytes\n\n";
    {
        std::cout << "Student lifecycle: ";
        Student s("Asha", "Chennai", "DSA01");
        std::cout << "\nDestroying:        ";
    }
    std::cout << "\n\n";
    {
        std::cout << "Staff lifecycle:   ";
        Staff st("Bala", "Madurai", "CSE");
        std::cout << "\nDestroying:        ";
    }
    std::cout << "\n\n";
    {
        std::cout << "TA lifecycle:      ";
        TeachingAssistant ta("Charan", "Salem", "DSA01", "CSE");
        std::cout << "\nDestroying:        ";
    }
    std::cout << '\n';
    return 0;
}

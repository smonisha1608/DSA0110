#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int id;
    std::string phone;
public:
    Person(std::string n, int i, std::string p)
        : name(std::move(n)), id(i), phone(std::move(p)) {}
    virtual ~Person() = default;
    std::string getName() const { return name; }
    int getId() const { return id; }
};

class Student : virtual public Person {
protected:
    std::string programme;
    double cgpa;
public:
    Student(std::string n, int i, std::string p, std::string prog, double c)
        : Person(std::move(n), i, std::move(p)), programme(std::move(prog)), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    std::string department;
    double salary;
public:
    Staff(std::string n, int i, std::string p, std::string dept, double sal)
        : Person(std::move(n), i, std::move(p)), department(std::move(dept)), salary(sal) {}
};

class TeachingAssistant : public Student, public Staff {
private:
    std::string assignedCourse;
public:
    TeachingAssistant(std::string n, int i, std::string p,
                      std::string prog, double c,
                      std::string dept, double sal, std::string course)
        : Person(std::move(n), i, std::move(p)),
          Student(n, i, p, std::move(prog), c),
          Staff(n, i, p, std::move(dept), sal),
          assignedCourse(std::move(course)) {}

    void display() const {
        std::cout << "TA: " << name << " (ID: " << id << ") | Prog: " << programme
                  << " | Dept: " << department << " | Course: " << assignedCourse << '\n';
    }
};

struct Fellowship {
    std::string agency;
    double stipend;
};

class ResearchScholar : public Student {
private:
    Fellowship fellowship;
public:
    ResearchScholar(std::string n, int i, std::string p,
                    std::string prog, double c, Fellowship f)
        : Person(std::move(n), i, std::move(p)),
          Student(n, i, p, std::move(prog), c),
          fellowship(std::move(f)) {}

    void display() const {
        std::cout << "Scholar: " << name << " (ID: " << id << ") | Agency: "
                  << fellowship.agency << " | Stipend: " << fellowship.stipend << '\n';
    }
};

int main() {
    TeachingAssistant ta("Ananya", 201, "9876543210", "M.Tech CSE", 9.1, "CSE", 25000.0, "DSA01");
    ResearchScholar rs("Vikram", 202, "9123456780", "Ph.D. AI", 9.4, {"DST-INSPIRE", 37000.0});

    ta.display();
    rs.display();
    return 0;
}

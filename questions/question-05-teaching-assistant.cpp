//A college teaching assistant is both: a Student ,an Employee
//Both roles share common information from Person.

#include <iostream>
using namespace std;

class Person
{
protected:
    string name;

public:

    Person(string n)
    {
        name = n;
        cout << "Person created" << endl;
    }

    void showPerson()
    {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person
{
protected:
    int rollNo;

public:

    Student(string n, int r)
        : Person(n)
    {
        rollNo = r;
        cout << "Student created" << endl;
    }

    void showStudentRole()
    {
        cout << "Student Roll No: "
             << rollNo << endl;
    }
};

class Employee : virtual public Person
{
protected:
    int employeeId;

public:

    Employee(string n, int id)
        : Person(n)
    {
        employeeId = id;
        cout << "Employee created" << endl;
    }

    void showEmployeeRole()
    {
        cout << "Employee ID: "
             << employeeId << endl;
    }
};

class TeachingAssistant :
    public Student,
    public Employee
{
private:
    int hours;

public:

    TeachingAssistant(
        string n,
        int r,
        int id,
        int h)
        : Person(n), Student(n, r),
          Employee(n, id)
    {
        hours = h;
        cout << "Teaching Assistant created"
             << endl;
    }

    void display()
    {
        showPerson();
        showStudentRole();
        showEmployeeRole();

        cout << "Working hours: "
             << hours << endl;
    }
};

int main()
{
    TeachingAssistant ta(
        "Aarav",
        124,
        501,
        12);

    ta.display();

    return 0;
}

//1.Why are two Person objects created?
//Because TeachingAssistant inherits from both Student and Employee, and both classes separately inherit from Person. Therefore, two copies of Person are created.
//2.What is the diamond inheritance problem?
//It happens when a class inherits from 2 classes that both inherit from the same base class, this can create duplicate base-class objects and ambiguity
//3.How can virtual inheritance solve the problem?
//Virtual inheritance ensures that only one shared copy of Person object is created for TeachingAssistant
//4.What changes are required in Student and Employee?
//change :- class Student : virtual public Person and class Employee : virtual public Person
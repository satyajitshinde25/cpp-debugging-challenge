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

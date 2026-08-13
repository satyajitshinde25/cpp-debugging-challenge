//A university charges different users differently.
//For example:
//Students receive one calculation
//Employees receive another
//The program should select the appropriate calculation dynamically

#include <iostream>
#include <stdexcept>
using namespace std;

class Service
{
public:

    virtual double calculate(
        double amount,
        double rate) = 0;
    virtual ~Service(){}
    void validate(double amount)
    {
        if (amount < 0)
            throw invalid_argument(
                "Amount cannot be negative");
    }
};

class StudentService : public Service
{
public:

    double calculate(
        double amount,
        double rate) override
    {
        return amount -
               (amount * rate / 100);
    }
};

class EmployeeService : public Service
{
public:

    double calculate(
        double amount,
        double rate) override
    {
        return amount +
               (amount * rate / 100);
    }
};

template <class T>
T maximum(T a, T b)
{
    if (a < b)
        return b;

    return a;
}

int main()
{
    Service* services[2];

    services[0] = new StudentService();
    services[1] = new EmployeeService();

    double amount = 1000;
    double rate = 10;

    try
    {
        services[0]->validate(amount);
        services[1]->validate(rate);

        double studentAmount =
            services[0]->calculate(
                amount, rate);

        double employeeAmount =
            services[1]->calculate(
                amount, rate);

        cout << "Student amount: "
             << studentAmount << endl;

        cout << "Employee amount: "
             << employeeAmount << endl;

        cout << "Higher amount: "
             << maximum(
                    studentAmount,
                    employeeAmount)
             << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: "
             << e.what() << endl;
    }

    delete services[0];
    delete services[1];

    return 0;
}


//1.How does runtime polymorphism work here?
//At the runtime, the correct calculate function is called on the basis of actual object
//2.Why is the base class pointer used?
//Base class pointer is used to achieve runtime polymorphism
//3.Why should the base class have a virtual destructor?
//To ensure that when a derived class object is deleted using a base class pointer, then the destructor is called correctly.
//4.What is the purpose of the template function?
//Template function can work with different datatypes, the purpose was only to work with different datatype
//5.What type of exception should be handled if the input amount is invalid?
//In this invalid_argument should be handled because a negative amount is  an invalid input
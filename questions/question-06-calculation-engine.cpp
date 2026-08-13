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

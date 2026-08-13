// Two machines in a laboratory require maintenance at fixed intervals.The program calculates:
//GCD of maintenance intervals
//LCM to determine when both machines require maintenance together
//prime factors of the common maintenance period

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b,a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

void printPrimeFactors(int n)
{
    cout << "Prime factors: ";

    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << n << " ";
            n = n / i;
        }
    }

    cout << endl;
}

int main()
{
    int machineA, machineB;

    cout << "Enter maintenance intervals: ";
    cin >> machineA >> machineB;

    int commonDivisor = gcd(machineA, machineB);
    int commonInterval = lcm(machineA, machineB);

    cout << "GCD: " << commonDivisor << endl;
    cout << "Next common maintenance after: "
         << commonInterval << " days" << endl;

    if (isPrime(commonInterval))
        cout << "Common interval is prime" << endl;
    else
        cout << "Common interval is not prime" << endl;

    printPrimeFactors(commonInterval);

    return 0;
}

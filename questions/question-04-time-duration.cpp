//An event team records the duration of multiple meetings.
//A Duration object stores: hours ,minutes
//The program uses operator overloading to add two meeting durations and compare them.

#include <iostream>
using namespace std;

class Duration
{
private:
    int hours;
    int minutes;

public:

    Duration()
    {
        hours = 0;
        minutes = 0;
    }

    Duration(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    Duration operator+(Duration other)
    {
        Duration result;

        result.hours = hours + other.hours;
        result.minutes = minutes + other.minutes;

        if (result.minutes >= 60)
        {
            result.hours++;
            result.minutes -= 60;
        }

        return result;
    }

    bool operator>(Duration other)
    {
        if (hours > other.hours)
            return true;

        if (hours == other.hours &&
            minutes > other.minutes)
            return true;

        return false;
    }

    void display()
    {
        cout << hours << " hours "
             << minutes << " minutes" << endl;
    }
};

int main()
{
    Duration meeting1(2, 45);
    Duration meeting2(1, 30);
    Duration meeting3(3, 20);

    Duration total = meeting1 + meeting2;

    cout << "Total duration: ";
    total.display();

    if (meeting3 > total)
        cout << "Meeting 3 is longer" << endl;
    else
        cout << "Combined duration is longer" << endl;

    return 0;
}

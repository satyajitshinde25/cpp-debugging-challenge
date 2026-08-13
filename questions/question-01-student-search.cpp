//A college stores student marks in sorted order.
//The program should find the first and last position of a particular mark using binary search and report how many students obtained that mark


#include <iostream>
using namespace std;

int lastPosition(int marks[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int answer = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (marks[mid] == target)
        {
            answer = mid;
            low = mid + 1;
        }
        else if (marks[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;
}

int firstPosition(int marks[], int n, int target)
{
    int low = 0;
    int high = n - 1;
    int answer = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (marks[mid] == target)
        {
            answer = mid;
            high = mid - 1;
        }
        else if (marks[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;
}

int main()
{
    int marks[] = {
        45, 52, 60, 60, 60,
        67, 72, 75, 75, 81
    };

    int n = 10;
    int target;

    cout << "Enter marks to search: ";
    cin >> target;

    int first = firstPosition(marks, n, target);
    int last = lastPosition(marks, n, target);

    if (first == -1)
    {
        cout << "Marks not found" << endl;
    }
    else
    {
        cout << "First position: " << first << endl;
        cout << "Last position: " << last << endl;
        cout << "Number of students: "
             << last - first + 1 << endl;
    }

    return 0;
}

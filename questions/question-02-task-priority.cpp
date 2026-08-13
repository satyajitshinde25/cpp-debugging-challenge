//A college event team receives tasks with different priority values. Lower priority numbers represent more urgent tasks.

#include <iostream>
using namespace std;

void sortPriorities(int priority[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int key = priority[i];
        int j = i - 1;

        while (j >= 0 && priority[j] >= key)
        {
            priority[j + 1] = priority[j];
            j--;
        }

        priority[j+1] = key;
    }
}

int removeDuplicatePriorities(int priority[], int n)
{
    if (n == 0)
        return 0;

    int index = 0;

    for (int i = 1; i <= n; i++)
    {
        if (priority[i] != priority[index])
        {
            index++;
            priority[index] = priority[i];
        }
    }

    return index;
}

void display(int priority[], int n)
{
    for (int i = 0; i < n; i++)
        cout << priority[i] << " ";

    cout << endl;
}

int main()
{
    int priority[] = {
        5, 2, 8, 3, 2,
        7, 4, 5, 1, 3
    };

    int n = 10;

    cout << "Original priorities: ";
    display(priority, n);

    sortPriorities(priority, n);

    cout << "Sorted priorities: ";
    display(priority, n);

    n = removeDuplicatePriorities(priority, n);

    cout << "Unique priorities: ";
    display(priority, n);

    return 0;
}

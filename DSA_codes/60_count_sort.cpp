#include <iostream>
#include <limits>
using namespace std;

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

int maximum(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countsort(int a[], int n)
{
    int max = maximum(a, n);
    int *count = new int[max + 1];
    int i, j;

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]] += 1;
    }

    i = 0, j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] -= 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {3, 12, 67, 4, 78, 1, 23, 3, 7, 5, 45};
    int n = sizeof(a) / sizeof(int);
    printarray(a, n);
    countsort(a, n);
    printarray(a, n);
    return 0;
}
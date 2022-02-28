#include <iostream>
using namespace std;

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "   ";
    }
    cout << endl;
}

void bubblesort(int *a, int n)
{
    int temp, issort = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issort = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issort = 0;
            }
        }
        if (issort)
        {
            return;
        }
    }
}

void insertionsort(int *a, int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void selectionsort(int *a, int n)
{
    int temp, index;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }
        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int main()
{
    int a[] = {3, 87, 1, 9, 2, 45, 71, 23, 51, 99, 456, 5, 31};
    int n = sizeof(a) / sizeof(int);
    printarray(a, n);
    selectionsort(a, n);
    printarray(a, n);
    return 0;
}
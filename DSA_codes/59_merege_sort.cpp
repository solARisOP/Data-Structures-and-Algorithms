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

void merge(int a[], int low, int mid, int high)
{
    int b[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++, k++;
        }
        else
        {
            b[k] = a[j];
            j++, k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++, k++;
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int a[] = {3, 12, 67, 4, 78, 1, 23, 3, 7, 5, 45};
    int n = sizeof(a) / sizeof(int);
    printarray(a, n);
    mergesort(a, 0, n - 1);
    printarray(a, n);
    return 0;
}
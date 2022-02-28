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

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (a[i] <= pivot) // finding greater than pivot
        {
            i++;
        }

        while (a[j] > pivot) // finding lesser than pivot
        {
            j--;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);
    swap(a[low], a[j]);
    
    return j;
}

void quicksort(int a[], int low, int high)
{
    int partitionindex;

    if (low < high)
    {
        partitionindex = partition(a, low, high);
        quicksort(a, low, partitionindex - 1);
        quicksort(a, partitionindex + 1, high);
    }
}

int main()
{
    int a[] = {0,2,0,0,1,2,1};
    int n = sizeof(a) / sizeof(int);
    // printarray(a, n);
    quicksort(a, 0, n - 1);
    printarray(a, n);
    return 0;
}
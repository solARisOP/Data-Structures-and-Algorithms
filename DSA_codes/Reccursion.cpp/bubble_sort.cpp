#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    if(n == 0 || n == 1)
    {
        return;
    }
    int issorted = 1;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            issorted = 0;
        }
    }
    if(issorted)
    {
        return;
    }
    else
    {
        bubblesort(arr, n-1);
    }
    
}

int main()
{
    int arr[] = {1,3,5,67,32,6,78,49,56,7};
    int size = sizeof(arr)/sizeof(int);
    bubblesort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"   ";
    }
    
    return 0;
}
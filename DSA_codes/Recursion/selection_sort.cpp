#include <iostream>
using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    
}

void selectionsort(int arr[], int n)
{
    if(n == 0 || n == 1)
    {
        return;
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]< arr[index])
        {
            index = i;
        }
    }
    swap(arr[0], arr[index]);

    selectionsort(arr+1, n-1);
    
}

int main()
{
    int arr[] = {1,3,5,67,32,6,78,49,56,7};
    int size = sizeof(arr)/sizeof(int);
    selectionsort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"   ";
    }
    
    return 0;
}
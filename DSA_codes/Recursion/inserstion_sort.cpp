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
void insertionsort(int arr[], int n)
{
    static int i = 0;
    if(i >= n)
    {
        return;
    }
    int j = i-1;
    int temp = arr[i];
    while(j>=0 && temp < arr[j])
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp; 
    i++;
    insertionsort(arr, n);
}

int main()
{
    int arr[] = {1,3,5,67,32,6,78,49,56,7};
    int size = sizeof(arr)/sizeof(int);
    insertionsort(arr, size);
    print(arr, size);
    return 0;
}
#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}

void insert(int arr[], int size, int index, int capacity, int element)
{
    if(size>=capacity)
    {
        cout<<"its size is greater than its capacity"<<endl;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    
}

int main()
{
    int arr[100]={1,2,9,23,56};
    int size = 5, index= 3, capacity=100, element= 7;
    insert(arr, size, index, capacity, element);
    size+=1;
    display(arr, size);
    return 0;
}
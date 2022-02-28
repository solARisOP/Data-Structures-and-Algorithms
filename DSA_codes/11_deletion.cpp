#include <iostream>
using namespace std;

    void display(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<endl;
        }
        
    }
    void deletion(int arr[], int size, int capacity, int index)
    {
        for (int i = index; i <size-1; i++)
        {
            arr[i]=arr[i+1];
        }
        
    }

int main()
{
    int arr[100]={6,45,33,78,51};
    int size = 5, capacity = 100, index = 2;
    deletion(arr, size, capacity, index);
    size-=1;
    display(arr, size);
    return 0;
}
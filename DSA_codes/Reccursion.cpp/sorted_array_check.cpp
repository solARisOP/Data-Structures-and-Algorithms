#include <iostream>
using namespace std;

bool issorted(int arr[], int size)
{
    if(size == 0 || size ==1)
    {
        return true;
    }
    if(arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return issorted(arr+1, size -1);
    }
}

int main()
{
    int arr[6] = {2, 4, 9, 12, 56, 88};
    int size = 6;
    if(issorted(arr, size))
    {
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}
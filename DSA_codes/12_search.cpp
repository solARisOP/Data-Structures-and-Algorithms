#include <iostream>
using namespace std;

int linear(int arr[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int binary(int arr[], int element, int size)
{
    int low=0, high = size-1, mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(element==arr[mid])
        {
            return mid;
        }
        else if(element>arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return -1;

}

int main()
{
    int arr[]={1,89,129,34,456, 76,234,378,1001,600};
    int size = sizeof(arr)/sizeof(int), element = 456; 
    int index = binary(arr, element, size); // for performing binary search your array must be sorted
    cout<<"the element is at arr["<<index<<"]"<<endl;
    return 0;
}
#include <iostream>
using namespace std;

bool binarysearch(int arr[], int s, int e, int key)
{

    if(s>e)
    {
        return false;
    }
    int m = (e+s)/2;
    if(arr[m] == key)
    {
        return true;
    }
    if(key<arr[m])
    {
        return binarysearch(arr, s, m-1, key);
    }
    else 
    {
        return binarysearch(arr, m+1, e, key);
    }
}

int main()
{
    int arr[] = {2, 5, 14, 19, 23, 39, 42, 48, 51, 56};
    int size =sizeof(arr)/sizeof(int);
    if(binarysearch(arr, 0, size-1, 0))
    {
        cout<<"element found"<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }
    return 0;
}
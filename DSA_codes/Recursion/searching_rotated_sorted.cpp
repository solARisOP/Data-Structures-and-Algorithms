#include <iostream>
using namespace std;

void print(int arr[], int s, int e)
{
    for(int i = s; i<=e; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int pivot(int arr[], int s, int e)
{
    if(s>=e)
    {
        return s; // base condition
    }

    int m = (e+s)/2;

    if(arr[m]>=arr[0])
    {
        return pivot(arr, m+1, e);
    }
    else
    {
        return pivot(arr, s, m);
    }
    
    
}

int binarysearch(int arr[], int s, int e, int key)
{
    print(arr, s, e);
    if(s>e)
    {
        return -1;
    }
    int m = (e+s)/2;
    if(arr[m] == key)
    {
        return m;
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

int search(int arr[], int s, int e, int key)
{
    if(arr[pivot(arr, s, e)] <= key && key <= arr[e])
    {
        return binarysearch(arr, pivot(arr, s, e), e, key);
    }
    else
    {
        return binarysearch(arr, s, pivot(arr, s, e)-1, key);
    }
}

int main()
{
    int arr[6] = {64, 80, 89, 92, 34, 63};
    int size =6;
    cout<< search(arr, 0, size-1, 89)<<endl;
    return 0;
}
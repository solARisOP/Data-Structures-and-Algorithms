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

int first(int arr[], int s, int e, int key)
{
    // print(arr, s, e);
    if(s>e)
    {
        return -1;
    }
    int m = (e+s)/2;
    if(arr[m] == key)
    {
        if(arr[m-1] == key)
            return first(arr, s, m-1, key);
        else
            return m;    
    }
    if(key<arr[m])
    {
        return first(arr, s, m-1, key);
    }
    else 
    {
        return first(arr, m+1, e, key);
    }
}

int last(int arr[], int s, int e, int key)
{
    // print(arr, s, e);
    if(s>e)
    {
        return -1;
    }
    int m = (e+s)/2;
    if(arr[m] == key)
    {
        if(arr[m+1] == key)
            return last(arr, m+1, e, key);
        else
            return m;
    }
    if(key<arr[m])
    {
        return last(arr, s, m-1, key);
    }
    else 
    {
        return last(arr, m+1, e, key);
    }
}


int main()
{
    int arr[10] = {2, 5, 14, 23, 23, 23, 23, 23, 51, 56};
    int size = 10;
    int f, l;
    f = first(arr, 0, size-1, 23);
    l = last(arr, 0, size -1, 23);
    cout<<f<<"  "<<l<<endl;
    cout<<"number of occurence "<<(l-f)+1<<endl;

    return 0;
}
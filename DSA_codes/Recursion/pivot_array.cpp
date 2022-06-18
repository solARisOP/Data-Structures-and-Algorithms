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
    print(arr, s, e);
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

int main()
{
    int arr[6] = {64, 80, 9, 12, 34, 63};
    int size = 6;
    int ans = pivot(arr, 0, size-1);
    cout<<ans<<endl;
    return 0;
}
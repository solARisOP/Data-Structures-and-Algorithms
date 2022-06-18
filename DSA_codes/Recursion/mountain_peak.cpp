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

int mountainpeak(int arr[], int s, int e)
{
    print(arr, s, e);
    int m = (e+s)/2;
    if(s<e)
    {
        if(arr[m]< arr[m+1])
        {
            return mountainpeak(arr, m+1, e);
        }

        else
        {
            return mountainpeak(arr, s, m);
        }
    }
    else
        return s; // base condition.
}

int main()
{
    int arr[10] = {2, 5, 140, 90, 40, 38, 22, 12, 10, 7};
    cout<<mountainpeak(arr, 0, 9)<<endl;
    return 0;
}
#include <iostream>
using namespace std;

int sum(int arr[], int size)
{
    if(size == 0)
    {
        return 0;
    }
    return arr[0] + sum(arr+1, size-1);
}

int main()
{
    int arr[6] = {6, 32, 1, 8, 3};
    int size = 6;
    int ans = sum(arr, size);
    cout<<ans<<endl;
    return 0;
}
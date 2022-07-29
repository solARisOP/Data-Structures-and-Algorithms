#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 4, 5, 19, 20};
    int arr2[] = {1, 3, 6, 9, 18};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(arr[i]>arr2[j])
            {
                swap(arr[i], arr2[j]);
            }
        }
    }

    for(auto i : arr) cout<<i<<" ";
    for(auto j : arr2) cout<<j<<" ";
    
    return 0;
}
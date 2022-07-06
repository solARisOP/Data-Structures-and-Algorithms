#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr+size);
    for(int i =0; i<size-1; i++)
    {
        int x = n+arr[i];
        int low = i+1, high = size-1;
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] == x) return 1;
            else if(arr[mid] > x) high = mid -1;
            else low = mid +1;
        }
    }
    return 0;
    
}

int main()
{
    int arr[] = {5, 20, 3, 2, 5, 80};
    cout<<findPair(arr, 6, 78);
    return 0;
}
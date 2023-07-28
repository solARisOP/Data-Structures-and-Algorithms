#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int findKRotation(vector<int> &arr){
    // Write your code here.
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int rotations = -1; 

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[mid])
        {
            if(arr[low] < ans)
            {
                ans = arr[low];
                rotations = low;
            }    
            low = mid + 1;
        }
        else
        {
            if(arr[mid]<ans)
            {
                ans = arr[mid];
                rotations = mid;
            }
            high = mid - 1;
        }
    }

    return rotations;
}

int main()
{
    
    return 0;
}
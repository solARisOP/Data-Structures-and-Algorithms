#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// painters partition
int solve(vector<int> &arr, int painters, int paintings)
{
    int n = arr.size();
    int paints=0;
    int pntrs = 1;
    for(int i =0; i<n; i++)
    {
        paints+=arr[i];
        if(paints > paintings)
        {
            pntrs++;
            paints = arr[i];
        }
    }
    if(pntrs <= painters) return 1;
    return 0;
}

int findLargestMinDistance(vector<int> arr, int k) {
    // Write Your Code Here
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        long long mid = low + (high - low)/2;

        int x = solve(arr, k, mid);
        if(x) high = mid - 1;
        else low = mid + 1;
    }

    return low; 
}

// split arrays
int solve(vector<int> &arr, int splits, int summs)
{
    int n = arr.size();
    int sum=0;
    int block = 1;
    for(int i =0; i<n; i++)
    {
        sum+=arr[i];
        if(sum > summs)
        {
            block++;
            sum = arr[i];
        }
    }
    if(block <= splits) return 1;
    return 0;
}

int largestSubarraySumMinimized(vector<int> arr, int k) {
    // Write Your Code Here
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        long long mid = low + (high - low)/2;

        int x = solve(arr, k, mid);
        if(x) high = mid - 1;
        else low = mid + 1;
    }

    return low; 
}

int main()
{
    
    return 0;
}
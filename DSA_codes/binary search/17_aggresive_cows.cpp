#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vector<int> arr, int k, int dist)
{
    int n = arr.size();
    int cows = 1;
    int last = arr[0];
    for(int i = 1; i<n; i++)
    {
        if(arr[i] - last >= dist)
        {
            cows++;
            last = arr[i];
        } 
        if(cows == k) return 1;
    }

    return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n-1] - stalls[0];

    while(low <= high)
    {
        long long mid = low + (high - low)/2;

        bool x = solve(stalls, k, mid);

        if(x) low = mid + 1;
        else high = mid - 1;
    }

    return high;
}

int main()
{
    
    return 0;
}
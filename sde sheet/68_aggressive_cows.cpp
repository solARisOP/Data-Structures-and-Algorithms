#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vi &arr, int k, int limit)
{
    int n = arr.size();
    int cow = 1;
    int last = arr[0];

    for (int i = 1; i < n; i++)
    {
        int dist = arr[i] - last;
        if (dist >= limit)
        {
            cow++;
            last = arr[i];
        }
        if (cow == k)
            return 1;
    }

    return 0;
}

int aggressiveCows(vector<int> &arr, int k)
{
    //    Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int low = 1;
    int high = arr[n - 1] - arr[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool x = solve(arr, k, mid);

        if (x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}

int main()
{

    return 0;
}
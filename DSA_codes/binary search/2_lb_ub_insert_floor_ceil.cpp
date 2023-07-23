#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int searchInsert(vector<int> &arr, int m)
{
    // Write your code here.
    return lower_bound(arr.begin(), arr.end(), m) - arr.begin();
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // Write your code here.
    sort(arr, arr + n);
    int f_idx = upper_bound(arr, arr + n, x) - arr;
    int c_idx = lower_bound(arr, arr + n, x) - arr;

    int flr = (!f_idx) ? -1 : arr[f_idx - 1];
    int cl = (c_idx == n) ? -1 : arr[c_idx];

    return {flr, cl};
}

int main()
{

    return 0;
}
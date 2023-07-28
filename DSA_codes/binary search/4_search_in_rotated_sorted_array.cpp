#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int search(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return mid;

        if (arr[mid] <= arr[high])
        {
            if (arr[mid] < k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (arr[low] <= k && k < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}
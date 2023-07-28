#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vector<int> arr, int roses, int bouques, int days)
{
    int n = arr.size();
    int bqs = 0, ros = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= days)
            ros++;
        else
        {
            ros = 0;
            continue;
        }

        if (ros == roses)
        {
            ros = 0;
            bqs++;
        }
        if (bqs == bouques)
            return 1;
    }

    return 0;
}

int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    if (m * k > arr.size())
        return -1;

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        int x = solve(arr, k, m, mid);

        if (x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{

    return 0;
}
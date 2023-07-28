#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int search(vector<int> &nums, int target)
{
    int n = nums.size();

    int low = 0, high = n - 1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    return 0;
}
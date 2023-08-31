#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int x = accumulate(begin(nums), end(nums), 0);
    if (x % 2)
        return false;
    x /= 2;
    vi prev(x + 1, 0), curr(x + 1, 0);
    for (int i = 0; i < n; i++)
        prev[0] = 1;
    if (nums[0] <= x)
        prev[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            bool pick = 0;
            if (j >= nums[i])
                pick = prev[j - nums[i]];
            bool n_pick = prev[j];

            curr[j] = pick || n_pick;
        }
        prev = curr;
    }

    return prev[x];
}

int main()
{

    return 0;
}
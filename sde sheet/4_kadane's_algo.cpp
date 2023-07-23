#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int maxProduct(vector<int> &nums)
{
    int pre = 1;
    int suff = 1;
    int n = nums.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (!pre)
            pre = 1;
        if (!suff)
            suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max({pre, suff, ans});
    }

    return ans;
}

int main()
{

    return 0;
}
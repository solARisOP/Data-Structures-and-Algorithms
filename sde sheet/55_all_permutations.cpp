#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int ind, vi &nums, vvi &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    int n = nums.size();
    for (int i = ind; i < n; i++)
    {
        swap(nums[i], nums[ind]);
        solve(ind + 1, nums, ans);
        swap(nums[i], nums[ind]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vvi ans;
    solve(0, nums, ans);
    return ans;
}

int main()
{

    return 0;
}
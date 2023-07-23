#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int ind, vi &nums, vi &sub, vvi &ans, int target, int sum)
{
    if (sum > target)
        return;
    if (sum == target)
    {
        ans.push_back(sub);
        return;
    }

    int n = nums.size();
    for (int i = ind; i < n; i++)
    {
        if (nums[i] > target)
            break;
        int x = nums[i];
        sub.push_back(nums[i]);
        solve(i + 1, nums, sub, ans, target, sum + nums[i]);
        sub.pop_back();
        while (i + 1 < n && nums[i + 1] == x)
            i++;
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vvi ans;
    vi sub;
    solve(0, candidates, sub, ans, target, 0);
    return ans;
}

int main()
{

    return 0;
}
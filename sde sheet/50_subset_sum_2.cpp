#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int i, vi &nums, vvi &ans, vi sub)
{
    ans.push_back(sub);
    int n = nums.size();
    for (int j = i; j < n; j++)
    {
        int x = nums[j];
        sub.push_back(nums[j]);
        solve(j + 1, nums, ans, sub);
        sub.pop_back();
        while (j + 1 < n && x == nums[j + 1])
            j++;
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vvi ans;
    solve(0, nums, ans, {});
    return ans;
}

int main()
{

    return 0;
}
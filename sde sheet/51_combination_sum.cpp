#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int i, vi &cands, int &target, vvi &ans, int sum, vi &subs)
{
    if (sum == target)
    {
        ans.push_back(subs);
        return;
    }
    if (sum > target)
        return;
    if (cands.size() == i)
        return;

    solve(i + 1, cands, target, ans, sum, subs);
    subs.push_back(cands[i]);
    solve(i, cands, target, ans, sum + cands[i], subs);
    subs.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vvi ans;
    vi subs;
    solve(0, candidates, target, ans, 0, subs);
    return ans;
}

int main()
{

    return 0;
}
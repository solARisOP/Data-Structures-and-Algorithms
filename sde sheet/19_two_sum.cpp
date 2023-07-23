#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int key = target - nums[i];
        if (mpp.find(key) != mpp.end())
            return {mpp[key], i};
        mpp[nums[i]] = i;
    }

    return {};
}

int main()
{

    return 0;
}
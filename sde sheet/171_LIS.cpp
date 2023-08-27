#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vi temp;
    temp.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(begin(temp), end(temp), nums[i]) - begin(temp);
            temp[ind] = nums[i];
        }
    }

    return len;
}

int main()
{

    return 0;
}
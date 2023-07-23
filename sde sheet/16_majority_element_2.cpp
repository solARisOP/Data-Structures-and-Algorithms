#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> majorityElement(vector<int> &nums)
{
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int c1 = 0, c2 = 0;
    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && ele2 != nums[i])
        {
            c1 = 1;
            ele1 = nums[i];
        }
        else if (c2 == 0 && ele1 != nums[i])
        {
            c2 = 1;
            ele2 = nums[i];
        }
        else if (ele1 == nums[i])
            c1++;
        else if (ele2 == nums[i])
            c2++;
        else
            c1--, c2--;
    }

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
            cnt1++;
        if (nums[i] == ele2)
            cnt2++;
    }
    if (cnt1 > n / 3)
        ans.push_back(ele1);
    if (cnt2 > n / 3)
        ans.push_back(ele2);
    return ans;
}

int main()
{
    
    return 0;
}
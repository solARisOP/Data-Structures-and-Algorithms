#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vi solve(vi arr, vi nums)
{
    int sx = arr.size();
    int sy = nums.size();

    vi ans;
    int i = 0, j = 0;
    while (i < sx && j < sy)
    {
        if (arr[i] <= nums[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(nums[j]);
            j++;
        }
    }

    while (i < sx)
    {
        ans.push_back(arr[i]);
        i++;
    }
    while (j < sy)
    {
        ans.push_back(nums[j]);
        j++;
    }

    return ans;
}
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    vi ans;
    int i = 0;
    while (i < k)
    {
        ans = solve(ans, kArrays[i]);
        i++;
    }

    return ans;
}

int main()
{

    return 0;
}
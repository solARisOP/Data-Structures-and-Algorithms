#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = j + 1, b = n - 1;
            while (a < b)
            {
                long long key = nums[i] * 1LL + nums[j] * 1LL + nums[a] * 1LL + nums[b] * 1LL;
                if (key == target)
                {
                    int x = nums[a];
                    int y = nums[b];
                    ans.push_back({nums[i], nums[j], nums[a], nums[b]});
                    while (a + 1 < n && nums[a + 1] == x)
                        a++;
                    while (b - 1 >= 0 && nums[b - 1] == x)
                        b--;
                    a++, b--;
                }
                else if (key < target)
                    a++;
                else
                    b--;
            }

            int x = nums[j];
            while (j + 1 < n && nums[j + 1] == x)
                j++;
        }

        int x = nums[i];
        while (i + 1 < n && nums[i + 1] == x)
            i++;
    }

    return ans;
}

int main()
{

    return 0;
}
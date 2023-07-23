#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int trap(vector<int> &height)
{
    int n = height.size();
    int r_max = height[n - 1];
    int l_max = height[0];
    int l = 0;
    int r = n - 1;

    int ans = 0;
    while (l <= r)
    {
        if (height[l] <= height[r])
        {
            if (l_max <= height[l])
                l_max = height[l];
            else
                ans += l_max - height[l];
            l++;
        }

        else
        {
            if (r_max <= height[r])
                r_max = height[r];
            else
                ans += r_max - height[r];
            r--;
        }
    }

    return ans;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height);
    return 0;
}
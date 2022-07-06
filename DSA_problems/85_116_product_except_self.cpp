#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> productExceptSelf(vector<ll> &arr, int n)
{
    ll pro = 1;
    vector<ll> ans(n);
    int count0 = 0;
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
            continue;
        }
        pro *= arr[i];
        flag = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!flag)
            ans[i] = 0;
        else if (count0 == 1)
        {
            if (arr[i] == 0)
                ans[i] = pro;
            else
                ans[i] = 0;
            continue;
        }

        else if (count0 > 1)
            ans[i] = 0;

        else
            ans[i] = pro / arr[i];
    }

    return ans;
}

int main()
{
    vector<ll> nums = {1, 0};
    for (auto i : productExceptSelf(nums, 2))
        cout << i << " ";
    return 0;
}
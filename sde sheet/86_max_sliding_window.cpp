#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<pii> dq;
    vi ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && i - dq.back().second >= k)
            dq.pop_back();
        while (!dq.empty() && dq.front().first <= nums[i])
            dq.pop_front();
        dq.push_front({nums[i], i});
        if (i + 1 >= k)
            ans.push_back(dq.back().first);
    }

    return ans;
}

int main()
{
    long double s = 1.2;
    cout<<s - floor(s);
    return 0;
}
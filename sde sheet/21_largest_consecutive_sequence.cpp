#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int longestConsecutive(vector<int> &nums)
{
    if (!nums.size())
        return 0;
    set<int> st(nums.begin(), nums.end());

    int maxi = 1, cnt = 1;
    int prev = INT_MIN;
    for (auto it : st)
    {
        if (prev == INT_MIN)
        {
            prev = it;
            continue;
        }
        else if (prev + 1 == it)
        {
            cnt++;
            maxi = max(cnt, maxi);
        }
        else
            cnt = 1;
        prev = it;
    }

    return maxi;
}

int longestConsecutive(vector<int> &nums)
{
    if (!nums.size()) return 0;
    
    unordered_set<int> st(nums.begin(), nums.end());
    int maxi = 1;
    for (auto it : st)
    {
        if (st.count(it - 1)) continue;
        
        int cnt = 1;
        while (st.count(it + 1))
        {
            cnt++;
            it++;
        }
        maxi = max(maxi, cnt);
    }

    return maxi;
}

int main()
{

    return 0;
}
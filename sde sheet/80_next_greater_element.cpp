#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> nextGreaterElement(vector<int> &sub, vector<int> &nums)
{
    stack<int> st;
    unordered_map<int, int> mpp;
    int i = nums.size() - 1;
    while (i >= 0)
    {
        while (!st.empty() && nums[i] > st.top()) st.pop();
        mpp[nums[i]] = (st.size()) ?st.top() : -1;
        st.push(nums[i]);
        i--;
    }

    vector<int> ans;
    i = 0;
    int n = sub.size();
    while (i < n)
    {
        ans.push_back(mpp[sub[i]]);
        i++;
    }

    return ans;
}

int main()
{

    return 0;
}
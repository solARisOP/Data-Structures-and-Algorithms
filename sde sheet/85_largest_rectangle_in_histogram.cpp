#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    stack<pii> st;
    vi left(n, -1), right(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= arr[i])
            st.pop();
        if (st.size())
            left[i] = st.top().second;
        st.push({arr[i], i});
    }

    while (st.size())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
            st.pop();
        if (st.size())
            right[i] = st.top().second;
        st.push({arr[i], i});
    }

    int maxi = -1e9;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i] * (right[i] - left[i] - 1));
    }

    return maxi;
}

int main()
{
    deque<int> dq;
    dq.push_front(1);
    dq.push_front(2);
    // dq.push_back(3);
    // dq.push_back(4);
    cout<<dq.front()<<dq.back();
    return 0;
}
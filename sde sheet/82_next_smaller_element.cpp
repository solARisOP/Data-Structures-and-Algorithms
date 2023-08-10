#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(st.size())ans.push_back(st.top());
        else ans.push_back(-1);
        st.push(arr[i]);
    }
    
    return ans;
}

int main()
{
    
    return 0;
}
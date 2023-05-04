#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs(int node, vi &vis, stack<int> &st, vi adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, st, adj);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vi vis(V, 0);
    vi ans;
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vi &vis, stack<int> &st, vi adj[])
{
    vis[node] = 1;

    for (int it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }

    st.push(node);
}

void k_dfs(int node, vi &vis, vi adj[])
{
    vis[node] = 1;

    for (int it : adj[node])
    {
        if (!vis[it])
            k_dfs(it, vis, adj);
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Write your code here.
    vi adj[v];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }
    vi vis(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, vis, st, adj);
    }

    vi adj_r[v];
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            adj_r[it].push_back(i);
        }
        vis[i] = 0;
    }

    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (vis[node])
            continue;
        k_dfs(node, vis, adj_r);
        cnt++;
    }

    return cnt;
}

int main()
{

    return 0;
}
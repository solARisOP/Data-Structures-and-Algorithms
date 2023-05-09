#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vii &adj, stack<int> &st, vi &vis)
{
    vis[node] = 1;
    for (int i : adj[node])
    {
        if (!vis[i])
            dfs(i, adj, st, vis);
    }

    st.push(node);
}

void k_dfs(int node, vi adj[], vi &vis)
{
    vis[node] = 1;
    for (int i : adj[node])
    {
        if (!vis[i])
            k_dfs(i, adj, vis);
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    stack<int> st;
    vi vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, st, vis);
    }

    vi adj_r[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;
        for (int it : adj[i])
        {
            adj_r[it].push_back(i);
        }
    }

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (vis[node])
            continue;
        scc++;
        k_dfs(node, adj_r, vis);
    }

    return scc;
}

int main()
{

    return 0;
}
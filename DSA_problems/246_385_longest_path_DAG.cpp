#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, stack<int> &topo, vi &vis, vi adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, topo, vis, adj);
    }

    topo.push(node);
}

int longestPath(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here.

    vi adj[n + 1];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    vi vis(n + 1, 0);
    stack<int> topo;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, topo, vis, adj);
    }

    int maxi = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        stack<int> st = topo;
        vi dist(n + 1, INT_MIN);
        dist[i] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (int it : adj[node])
            {
                if (dist[it] < dist[node] + 1)
                {
                    dist[it] = dist[node] + 1;
                }
            }
        }

        maxi = max(maxi, *max_element(dist.begin(), dist.end()));
    }

    return maxi;
}

int main()
{

    return 0;
}
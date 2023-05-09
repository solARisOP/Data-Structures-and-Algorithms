#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int timer = 1;
void dfs(int node, int parent, vi &vis, vi &tin, vi &low, vi adj[], vii &ans)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (int it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, adj, ans);
            low[node] = min(low[it], low[node]);
            
            if (low[it] > tin[node])
            {
                ans.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[it], low[node]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vi adj[n];
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vii ans;
    vi tin(n, 0), low(n, 0), vis(n, 0);
    dfs(0, 0, vis, tin, low, adj, ans);

    return ans;
}

int main()
{

    return 0;
}
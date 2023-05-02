#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs_graph(int node, vi &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] == 1 && !vis[i])
        {
            dfs_graph(i, vis, adj);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    vi vis(V, 0);
    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs_graph(i, vis, adj);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs_graph(int node, vi &vis, vi &dfs, vi adj[])
{
    vis[node] = 1;
    dfs.push_back(node);
    for (int it : adj[node])
    {
        if (!vis[it])
            dfs_graph(it, vis, dfs, adj);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vi vis(V, 0), dfs;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs_graph(i, vis, dfs, adj);
    }

    return dfs;
}

int main()
{

    return 0;
}
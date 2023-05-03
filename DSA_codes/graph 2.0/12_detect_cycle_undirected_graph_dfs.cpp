#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool dfs(int src, int parent, vi &vis, vi adj[])
{
    vis[src] = 1;
    for (int adj_node : adj[src])
    {
        if (!vis[adj_node])
        {
            if (dfs(adj_node, src, vis, adj)) return true;
        }
        else if (adj_node != parent) return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vi vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj)) return true;
        }
    }

    return false;
}
int main()
{

    return 0;
}
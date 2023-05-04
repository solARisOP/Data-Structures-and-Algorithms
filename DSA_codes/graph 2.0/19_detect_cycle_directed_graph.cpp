#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool dfs(int src, vi &vis, vi &path, vi adj[])
{
    vis[src] = 1;
    path[src] = 1;

    for (int node : adj[src])
    {
        if (!vis[node])
        {
            if (dfs(node, vis, path, adj)) return true;
        }
        else if (path[node]) return true;
    }

    path[src] = 0;
    return false;
}

// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vi vis(V, 0), path(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, path, adj)) return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}
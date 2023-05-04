#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool dfs(int src, vi adj[], vi &col)
{
    if (col[src] == -1) col[src] = 1;

    for (int adj_node : adj[src])
    {
        if (col[adj_node] == -1)
        {
            col[adj_node] = !col[src];
            if (!dfs(adj_node, adj, col)) return false;
        }
        else if (col[adj_node] == col[src]) return false;
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vi col(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            if (!dfs(i, adj, col))return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
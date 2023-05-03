#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool bfs(int src, vi &vis, vi adj[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int adj_node : adj[node])
        {
            if (!vis[adj_node])
            {
                vis[adj_node] = 1;
                q.push({adj_node, node});
            }
            else if (adj_node != parent) return true;
        }
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
            if (bfs(i, vis, adj)) return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}
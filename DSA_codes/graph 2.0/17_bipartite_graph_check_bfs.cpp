#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool bfs(int src, vi adj[], vi &col)
{
    col[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int adj_node : adj[node])
        {
            if (col[adj_node] == -1)
            {
                col[adj_node] = !col[node];
                q.push(adj_node);
            }
            else
            {
                if (col[adj_node] == col[node])
                    return false;
            }
        }
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
            if (!bfs(i, adj, col))
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
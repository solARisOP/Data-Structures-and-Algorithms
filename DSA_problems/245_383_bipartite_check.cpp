#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool dfs(int src, vi adj[], vi &col)
{
    if (col[src] == -1)
        col[src] = 1;

    for (int adj_node : adj[src])
    {
        if (col[adj_node] == -1)
        {
            col[adj_node] = !col[src];
            if (!dfs(adj_node, adj, col))
                return false;
        }
        else if (col[adj_node] == col[src])
            return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int V = edges.size();
    vi adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (edges[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vi col(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (col[i] == -1)
        {
            // col[i] = 1;
            if (!dfs(i, adj, col))
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}
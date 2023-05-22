#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    vp adj[n + 1];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }

    vi dist(n + 1, 1e9);
    dist[src] = 0;

    queue<pii> q;
    q.push({0, src});
 
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int node = it.second;
        int dis = it.first;

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dis + wt < dist[v])
            {
                dist[v] = dis + wt;
                q.push({dist[v], v});
            }
        }
    }

    return (dist[dst] != 1e9) ? dist[dst] : -1;
}

int main()
{

    return 0;
}
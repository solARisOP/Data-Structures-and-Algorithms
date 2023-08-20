#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src)
{
    // Write your code here.
    vp adj[vertices];
    for (auto it : vec)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pii, vp, greater<pii>> pq;
    vi dist(vertices, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        int u = x.second;
        int dis = x.first;

        for (auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;

            if (wt + dis < dist[v])
            {
                dist[v] = wt + dis;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}
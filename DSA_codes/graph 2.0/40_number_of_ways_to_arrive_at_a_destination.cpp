#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int countPaths(int n, vector<vector<int>> &roads)
{
    // code here
    int mod = 1e9;
    vp adj[n];
    for (auto it : roads)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pii, vp, greater<pii>> pq;

    vi dist(n, 1e9), path(n, 0);

    dist[0] = 0;
    path[0] = 1;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;

        pq.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            int final = (dis + wt) % mod;
            if (final < dist[v])
            {
                dist[v] = final;
                pq.push({dist[v], v});
                path[v] = path[node];
            }
            else if (dis + wt == dist[v])
            {
                path[v] = (path[v] + path[node]) % mod;
            }
        }
    }

    return path[n - 1];
}

int main()
{

    return 0;
}
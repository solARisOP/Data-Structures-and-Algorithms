#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int CheapestFLight(int n, vii &flights, int src, int dst, int K)
{
    // Code here
    vp adj[n];
    int m = flights.size();
    for (int i = 0; i < m; i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];

        adj[u].push_back({v, wt});
    }

    queue<pair<int, pii>> q;
    vi dist(n, 1e9);
    dist[src] = 0;
    q.push({0, {0, src}});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int dis = it.second.first;
        int node = it.second.second;

        if (stops > K)
            continue;
        for (auto x : adj[node])
        {
            int v = x.first;
            int wt = x.second;

            if (dis + wt < dist[v])
            {
                dist[v] = dis + wt;
                q.push({stops + 1, {dist[v], v}});
            }
        }
    }

    return (dist[dst] == 1e9) ? -1 : dist[dst];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vp adj[n];
    for (auto it : flights)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
    }

    vi dist(n, 1e9);
    queue<pair<int, pii>> q;

    q.push({0, {0, src}});
    dist[src] = 0;

    while (!q.empty())
    {
        int stops = q.front().first;
        int dis = q.front().second.first;
        int node = q.front().second.second;

        q.pop();

        if (stops > k)
            continue;
        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[v] > wt + dis)
            {
                dist[v] = wt + dis;
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
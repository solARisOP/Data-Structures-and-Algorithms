#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pii, vp, greater<pii>> pq;

    vi dist(V, 1e9);
    dist[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist_so_far = pq.top().first;

        pq.pop();

        for (auto it : adj[node])
        {
            int u = it[0];
            int wt = it[1];

            if (dist_so_far + wt < dist[u])
            {
                dist[u] = dist_so_far + wt;
                pq.push({dist[u], u});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}
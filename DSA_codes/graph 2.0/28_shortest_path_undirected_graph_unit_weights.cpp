#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vi shortestPath(vii &edges, int N, int M, int src)
{
    // code here
    vi adj[N];

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dist(N, 1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for (int &it : dist)
        if (it == 1e9)
            it = -1;

    return dist;
}

int main()
{

    return 0;
}
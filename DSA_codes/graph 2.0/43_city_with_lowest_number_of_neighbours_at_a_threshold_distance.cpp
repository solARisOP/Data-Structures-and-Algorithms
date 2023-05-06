#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// using floyd warshell
int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{

    vii mat(n, vi(n, 1e9));

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        mat[u][v] = wt;
        mat[v][u] = wt;
    }
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = 0;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    int cnt = n;
    int citi = -1;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] <= distanceThreshold)
                k++;
        }
        if (k <= cnt)
        {
            cnt = k;
            citi = i;
        }
    }

    return citi;
}

// using dijkstra
int findCity_dijkstra(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
{

    vp adj[n];
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vii mat;
    for (int i = 0; i < n; i++)
    {
        priority_queue<pii, vp, greater<pii>> pq;

        vi dist(n, 1e9);
        dist[i] = 0;

        pq.push({0, i});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist_so_far = pq.top().first;

            pq.pop();

            for (auto it : adj[node])
            {
                int u = it.first;
                int wt = it.second;

                if (dist_so_far + wt < dist[u])
                {
                    dist[u] = dist_so_far + wt;
                    pq.push({dist[u], u});
                }
            }
        }

        mat.push_back(dist);
    }

    int cnt = n;
    int citi = -1;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] <= distanceThreshold)
                k++;
        }
        if (k <= cnt)
        {
            cnt = k;
            citi = i;
        }
    }

    return citi;
}    

int main()
{

    return 0;
}
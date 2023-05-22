#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int isNegativeWeightCycle(int V, vector<vector<int>> edges)
{
    // Code here
    for (int s = 0; s < V; s++)
    {
        vi dist(V, INT_MAX);
        dist[s] = 0;

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{

    return 0;
}
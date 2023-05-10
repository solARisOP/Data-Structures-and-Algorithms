#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
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
    set<pii> st;
    vi dist(vertices, INT_MAX);

    st.insert({0, source});

    dist[source] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        st.erase(it);

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dis + wt < dist[v])
            {
                if (dist[v] < INT_MAX)
                    st.erase({dist[v], v});
                dist[v] = dis + wt;
                st.insert({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}
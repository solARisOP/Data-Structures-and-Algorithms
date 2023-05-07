#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<pair<int, pii>> edges;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int u = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {u, node}});
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);
    int mst = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionBySize(u, v);
            mst += wt;
        }
    }

    return mst;
}

int main()
{

    return 0;
}
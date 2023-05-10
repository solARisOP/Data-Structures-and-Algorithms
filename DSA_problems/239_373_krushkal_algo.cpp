#include <bits/stdc++.h>
using namespace std;
#include "E:\DSA notes and codes\DSA_codes\graph 2.0\46_disjoint_set.h"


#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    // Write your code here.
    priority_queue<pii, vp, greater<pii>> pq;
    vector<pair<int, pii>> edges;

    for (auto &it : graph)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(n + 1);

    int mst = 0;
    for (auto it : edges)
    {
        int u = it.second.first;
        int v = it.second.second;
        int wt = it.first;

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
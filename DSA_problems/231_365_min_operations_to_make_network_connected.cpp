#include <bits/stdc++.h>
using namespace std;
#include "E:\DSA notes and codes\DSA_codes\graph 2.0\46_disjoint_set.h"

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int makeConnected(int n, vector<vector<int>> &connections)
{
    DisjointSet ds(n);

    int extraedges = 0;
    for (auto it : connections)
    {
        int u = it[0];
        int v = it[1];

        if (ds.findUPar(u) != ds.findUPar(v))
            ds.unionBySize(u, v);
        else
            extraedges++;
    }

    int comps = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findUPar(i) == i)
            comps++;
    }

    if (extraedges >= comps - 1)
        return comps - 1;
    return -1;
}

int main()
{

    return 0;
}
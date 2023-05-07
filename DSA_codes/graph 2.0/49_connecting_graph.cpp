#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int Solve(int n, vector<vector<int>> &edges)
{
    // code here
    DisjointSet ds(n);
    int extraedges = 0;
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        if (ds.findUPar(u) == ds.findUPar(v))
            extraedges++;
        else
            ds.unionBySize(u, v);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findUPar(i) == i)
            cnt++;
    }

    if (extraedges >= cnt - 1)
        return cnt - 1;
    return -1;
}

int main()
{

    return 0;
}
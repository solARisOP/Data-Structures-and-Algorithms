#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    int n = adj.size();
    int m = adj[0].size();

    DisjointSet ds(V);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (adj[i][j])
                ds.unionBySize(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.findUPar(i) == i)
            ans++;
    }

    return ans;
}

int main()
{

    return 0;
}
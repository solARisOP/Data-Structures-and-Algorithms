#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int maxRemove(vector<vector<int>> &stones, int n)
{
    // Code here
    int maxrow = 0;
    int maxcol = 0;
    for (auto it : stones)
    {
        maxrow = max(it[0], maxrow);
        maxcol = max(it[1], maxcol);
    }

    DisjointSet ds(maxrow + maxcol + 1);
    unordered_map<int, int> mpp;
    for (auto it : stones)
    {
        int row = it[0];
        int col = it[1] + maxrow + 1;
        ds.unionBySize(row, col);
        mpp[row] = 1;
        mpp[col] = 1;
    }

    int cnt = 0;
    for (auto it : mpp)
    {
        if (ds.findUPar(it.first) == it.first)
            cnt++;
    }

    return n - cnt;
}

int main()
{

    return 0;
}
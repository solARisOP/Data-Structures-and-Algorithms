#include <bits/stdc++.h>
// #include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }

        return parent[n] = findUPar(parent[n]);
    }

    void unionByRank(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else if (rank[up_v] < rank[up_u])
        {
            parent[up_v] = up_u;
        }
        else
        {
            parent[up_v] = up_u;
            rank[up_v]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;

        if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

bool isvalid(int r, int c, int n, vii &grid)
{
    return (r >= 0 && r < n && c >= 0 && c < n && grid[r][c]);
}

int MaxConnection(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();

    DisjointSet ds(n * n);
    int maxsize = 1;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!grid[i][j])
                continue;
            for (int ind = 0; ind < 4; ind++)
            {
                int row = i + dr[ind];
                int col = j + dc[ind];
                if (isvalid(row, col, n, grid))
                {
                    int u = i * n + j;
                    int v = row * n + col;
                    ds.unionBySize(u, v);
                    int up = ds.findUPar(u);
                    maxsize = max(maxsize, ds.size[up]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
                continue;
            set<int> st;
            for (int ind = 0; ind < 4; ind++)
            {
                int row = i + dr[ind];
                int col = j + dc[ind];
                if (isvalid(row, col, n, grid))
                {
                    int u = row * n + col;
                    int up = ds.findUPar(u);
                    st.insert(up);
                }
            }
            int ans = 1;
            for (auto it : st)
                ans += ds.size[it];
            maxsize = max(maxsize, ans);
        }
    }

    return maxsize;
}

int main()
{

    return 0;
}
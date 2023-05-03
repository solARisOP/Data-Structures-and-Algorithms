#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs(int row, int col, vii &grid, vii &vis, vp &shape, int row0, int col0)
{
    vis[row][col] = 1;
    shape.push_back({row - row0, col - col0});

    int n = grid.size();
    int m = grid[0].size();
    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    for (int i = 0; i < 4; i++)
    {
        int r = row + delrow[i];
        int c = col + delcol[i];
        if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1)
        {
            dfs(r, c, grid, vis, shape, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here

    int n = grid.size();
    int m = grid[0].size();

    set<vp> st;
    vii vis(n, vi(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vp shape;
            if (!vis[i][j] && grid[i][j])
            {
                dfs(i, j, grid, vis, shape, i, j);
                st.insert(shape);
            }
        }
    }

    return st.size();
}

int main()
{

    return 0;
}
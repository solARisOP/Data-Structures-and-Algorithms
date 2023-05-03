#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs(int row, int col, vii &grid, vii &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    for (int x = 0; x < 4; x++)
    {
        int i = row + delrow[x];
        int j = col + delcol[x];
        if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] == 1)
        {
            dfs(i, j, grid, vis);
        }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vii vis(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !vis[i][j] && grid[i][j] == 1)
            {
                dfs(i, j, grid, vis);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
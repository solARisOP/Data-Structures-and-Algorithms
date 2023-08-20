#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvc vector<vector<char>>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int r, int c, vvc &grid, vvi &vis)
{
    int m = grid.size();
    int n = grid[0].size();
    return (r >= 0 && r < m && c >= 0 && c < n && !vis[r][c] && grid[r][c] == '1');
}

void dfs(int row, int col, vvi &vis, vvc &grid, int delrow[], int delcol[])
{
    vis[row][col] = 1;

    for (int i = 0; i < 4; i++)
    {
        int n_row = row + delrow[i];
        int n_col = col + delcol[i];
        if (isvalid(n_row, n_col, grid, vis))
        {
            dfs(n_row, n_col, vis, grid, delrow, delcol);
        }
    }
}

int numIslands(vvc &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vvi vis(m, vi(n, 0));

    int delrow[] = {0, -1, 0, 1};
    int delcol[] = {-1, 0, 1, 0};

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isvalid(i, j, grid, vis))
            {
                ans++;
                dfs(i, j, vis, grid, delrow, delcol);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
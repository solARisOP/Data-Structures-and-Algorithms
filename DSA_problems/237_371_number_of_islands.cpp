#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int i, int j, int n, int m, vector<vector<char>> &grid)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1');
}

void dfs(int row, int col, vii &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nr = row + delr[i];
        int nc = col + delc[i];
        if (isvalid(nr, nc, n, m, grid) && !vis[nr][nc])
            dfs(nr, nc, vis, grid);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vii vis(n, vi(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !vis[i][j])
            {
                cnt++;
                dfs(i, j, vis, grid);
            }
        }
    }

    return cnt;
}

int main()
{

    return 0;
}
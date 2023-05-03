#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void bfs(int row, int col, vii &vis, vector<vector<char>> &grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int n = grid.size();
    int m = grid[0].size();
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int delta_row = -1; delta_row <= 1; delta_row++)
        {
            for (int delta_col = -1; delta_col <= 1; delta_col++)
            {
                int r = i + delta_row;
                int c = j + delta_col;
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == '1')
                {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vii vis(n, vi(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                ans++;
                bfs(i, j, vis, grid);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
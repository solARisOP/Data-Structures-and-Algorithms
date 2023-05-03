#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void bfs(int row, int col, vector<vector<char>> &mat, vii &vis)
{
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;

    q.push({row, col});

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int x = 0; x < 4; x++)
        {
            int i = r + delrow[x];
            int j = c + delcol[x];
            if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] == 'O')
            {
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    vii vis(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && !vis[i][j] && mat[i][j] == 'O')
            {
                bfs(i, j, mat, vis);
            }
        }
    }

    vector<vector<char>> ans(mat);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                ans[i][j] = 'X';
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
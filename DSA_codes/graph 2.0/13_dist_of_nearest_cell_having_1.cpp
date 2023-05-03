#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vii vis(n, vi(m, 0));
    vii dis(n, vi(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j])
            {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        dis[r][c] = dist;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, dist + 1});
            }
        }
    }

    return dis;
}

int main()
{

    return 0;
}
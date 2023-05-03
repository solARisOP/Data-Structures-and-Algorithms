#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vii vis(n, vi(m, 0));
    int cntfrsh = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
                cntfrsh++;
        }
    }

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};
    int cnt = 0;
    int tm = 0;
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm = max(tm, t);

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
                cnt++;
            }
        }
    }

    if (cnt != cntfrsh) return -1;
    return tm;
}

int main()
{

    return 0;
}
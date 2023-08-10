#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int r, int c, vvi &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || !grid[r][c] || grid[r][c] == 2)
        return 0;
    return 1;
}

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<pii, int>> q;
    int m = grid.size();
    int n = grid[0].size();
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                q.push({{i, j}, 0});
            if (grid[i][j] == 1)
                cnt++;
        }
    }

    int r_c[4] = {0, -1, 0, 1};
    int c_c[4] = {-1, 0, 1, 0};

    int ans = 0;
    while (q.size())
    {
        auto it = q.front();
        q.pop();

        int r = it.first.first;
        int c = it.first.second;

        int tme = it.second;
        ans = max(ans, tme);

        for (int i = 0; i < 4; i++)
        {
            int nr = r_c[i] + r;
            int nc = c_c[i] + c;

            if (isvalid(nr, nc, grid))
            {
                grid[nr][nc] = 2;
                q.push({{nr, nc}, tme + 1});
                --cnt;
            }
        }
    }

    return (!cnt) ? ans : -1;
}

int main()
{

    return 0;
}
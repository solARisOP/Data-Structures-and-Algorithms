#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// bfs
bool isvalid(int r, int c, vvi &vis)
{
    int m = vis.size();
    int n = vis[0].size();

    return r >= 0 && r < m && c >= 0 && c < n && !vis[r][c];
}

int swimInWater(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    vvi vis(m, vi(n, 0));

    vis[0][0] = 1;
    pq.push({grid[0][0], {0, 0}});

    int delr[] = {0, -1, 0, 1};
    int delc[] = {-1, 0, 1, 0};
    while (!pq.empty())
    {
        int t = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (r == m - 1 && c == n - 1)
            return t;

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delr[i];
            int ncol = c + delc[i];

            if (isvalid(nrow, ncol, vis))
            {
                if (grid[nrow][ncol] <= t)
                    pq.push({t, {nrow, ncol}});
                else
                    pq.push({grid[nrow][ncol], {nrow, ncol}});

                vis[nrow][ncol] = 1;
            }
        }
    }

    return -1;
}

// binary search
bool isvalid(int r, int c, vvi &vis)
{
    int m = vis.size();
    int n = vis[0].size();

    return r >= 0 && r < m && c >= 0 && c < n && !vis[r][c];
}

bool dfs(int r, int c, int mini, vvi &grid, vvi &vis)
{
    vis[r][c] = 1;
    if (mini < grid[r][c])
        return false;
    if (r == grid.size() - 1 && c == grid[0].size() - 1)
        return true;

    int delr[] = {0, -1, 0, 1};
    int delc[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int nrow = r + delr[i];
        int ncol = c + delc[i];
        if (isvalid(nrow, ncol, vis))
        {
            if (dfs(nrow, ncol, mini, grid, vis))
                return true;
        }
    }

    return false;
}

int swimInWater(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int low = grid[0][0];
    int high = 0;
    for (int i = 0; i < m; i++)
    {
        high = max(high, *max_element(grid[i].begin(), grid[i].end()));
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vvi vis(m, vi(n, 0));

        if (dfs(0, 0, mid, grid, vis))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{

    return 0;
}
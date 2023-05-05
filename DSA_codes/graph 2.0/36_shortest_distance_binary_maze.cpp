#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int shortestPath(vii &grid, pii source, pii destination)
{
    if (source.first == destination.first && source.second == destination.second)
        return 0;
    // code here
    int n = grid.size();
    int m = grid[0].size();

    vii dist(n, vi(m, 1e9));

    queue<pair<int, pii>> q;

    int x = source.first, y = source.second;

    dist[x][y] = 0;

    q.push({0, {x, y}});
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int r = row + delrow[i];
            int c = col + delcol[i];

            if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] && dis + 1 < dist[r][c])
            {

                if (destination.first == r && destination.second == c)
                    return dis + 1;
                dist[r][c] = dis + 1;
                q.push({dist[r][c], {r, c}});
            }
        }
    }

    return -1;
}

int main()
{

    return 0;
}
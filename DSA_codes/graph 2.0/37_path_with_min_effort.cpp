#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int MinimumEffort(vector<vector<int>> &heights)
{
    // Code here
    int n = heights.size();
    int m = heights[0].size();
    vii dist(n, vi(m, 1e9));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return dis;
        for (int i = 0; i < 4; i++)
        {
            int r = row + delrow[i];
            int c = col + delcol[i];
            if (r >= 0 && c >= 0 && r < n && c < m)
            {
                int neweffort = max(dis, abs(heights[row][col] - heights[r][c]));
                if (neweffort < dist[r][c])
                {
                    dist[r][c] = neweffort;
                    pq.push({neweffort, {r, c}});
                }
            }
        }
    }

    return 0;
}

int main()
{

    return 0;
}
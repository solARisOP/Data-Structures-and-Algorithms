#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vi prev(n, 0), curr(n, 0);
    prev[0] = curr[0] = grid[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!i && !j)
                continue;
            int up = 1e9, left = 1e9;
            if (i > 0)
                up = grid[i][j] + prev[j];
            if (j > 0)
                left = grid[i][j] + curr[j - 1];

            curr[j] = min(up, left);
        }
        prev = curr;
    }
    return prev[n - 1];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int i, int j, int n, int m, int initial, vvi &image)
{
    return (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == initial);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];
    vvi ans(image);
    int m = image.size();
    int n = image[0].size();

    queue<pii> q;
    ans[sr][sc] = color;
    q.push({sr, sc});

    int delr[] = {0, -1, 0, 1};
    int delc[] = {-1, 0, 1, 0};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = row + delr[i];
            int c = col + delc[i];
            if (isvalid(r, c, m, n, initial, image) && ans[r][c] != color)
            {
                ans[r][c] = color;
                q.push({r, c});
            }
        }
    }

    return ans;
}

int main()
{
    
    return 0;
}
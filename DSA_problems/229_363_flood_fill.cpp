#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int i, int j, int n, int m, int initial, vii &image)
{
    return (i >= 0 && i < n && j >= 0 && j < m && image[i][j] == initial);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    queue<pii> q;
    int n = image.size();
    int m = image[0].size();

    int initial = image[sr][sc];

    vii ans(image);
    ans[sr][sc] = color;
    q.push({sr, sc});

    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = row + delr[i];
            int nc = col + delc[i];

            if (isvalid(nr, nc, n, m, initial, image) && ans[nr][nc] != color)
            {
                ans[nr][nc] = color;
                q.push({nr, nc});
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
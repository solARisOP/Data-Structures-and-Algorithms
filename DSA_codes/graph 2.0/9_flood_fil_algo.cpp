#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs(int sr, int sc, int in_color, int newColo, vii &image, vii &ans, int delrow[], int delcol[])
{
    ans[sr][sc] = newColo;
    int n = image.size(), m = image[0].size();
    for (int x = 0; x < 4; x++)
    {
        int i = sr + delrow[x];
        int j = sc + delcol[x];
        if (i >= 0 && i < n && j >= 0 && j < m && ans[i][j] != newColo && image[i][j] == in_color)
        {
            dfs(i, j, in_color, newColo, image, ans, delrow, delcol);
        }
    }
}

vector<vector<int>> floodFill(vii &image, int sr, int sc, int newColo)
{
    // Code here
    int in_color = image[sr][sc];
    int n = image.size(), m = image[0].size();
    vii ans(image);

    int delrow[] = {0, 1, 0, -1};
    int delcol[] = {1, 0, -1, 0};

    dfs(sr, sc, in_color, newColo, image, ans, delrow, delcol);

    return ans;
}

int main()
{

    return 0;
}
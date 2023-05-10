#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isvalid(int i, int j, int n, vii &mat)
{
    return (i >= 0 && i < n && j >= 0 && j < n && mat[i][j]);
}

void dfs(int row, int col, string s, vector<string> &ans,
         int delr[], int delc[], vii &mat, vii &vis, string &move)
{
    vis[row][col] = 1;
    int n = mat.size();

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(s);
        vis[row][col] = 0;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nr = row + delr[i];
        int nc = col + delc[i];

        if (isvalid(nr, nc, n, mat) && !vis[nr][nc])
        {
            dfs(nr, nc, s + move[i], ans, delr, delc, mat, vis, move);
        }
    }

    vis[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &mat, int n)
{
    // Your code goes here
    vii vis(n, vi(n, 0));
    int delr[] = {-1, 0, 1, 0};
    int delc[] = {0, 1, 0, -1};
    string move = "URDL";
    vector<string> ans;
    string s;

    if (!mat[0][0])
        return ans;

    dfs(0, 0, s, ans, delr, delc, mat, vis, move);

    return ans;
}

int main()
{

    return 0;
}
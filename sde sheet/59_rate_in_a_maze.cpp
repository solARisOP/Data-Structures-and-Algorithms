#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool is_valid(int i, int j, int n, vvi &dp, vvi &maze)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
        return false;
    else if (dp[i][j] || !maze[i][j])
        return false;
    else
        return true;
}
void solve(int r, int c, vvi &maze, vvi &dp, vector<string> &ans, string &s)
{
    if (r == maze.size() - 1 && c == maze.size() - 1)
    {
        ans.push_back(s);
        return;
    }
    int row[] = {0, -1, 0, 1};
    int col[] = {-1, 0, 1, 0};
    string in = "LURD";

    for (int i = 0; i < 4; i++)
    {
        if (is_valid(r + row[i], c + col[i], maze.size(), dp, maze))
        {
            dp[r + row[i]][c + col[i]] = 1;
            s += in[i];
            solve(r + row[i], c + col[i], maze, dp, ans, s);
            s.pop_back();
            dp[r + row[i]][c + col[i]] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    // Your code goes here
    vector<string> ans;
    if (!m[0][0])
        return ans;
    vvi dp(n, vi(n, 0));
    string s;
    dp[0][0] = 1;
    solve(0, 0, m, dp, ans, s);
    return ans;
}

int main()
{

    return 0;
}
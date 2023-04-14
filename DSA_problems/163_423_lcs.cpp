#include <bits/stdc++.h>
using namespace std;

#define str string
#define vi vector<int>
#define vii vector<vi>

int solve(int x, int y, str s1, str s2, vii &dp)
{
    if(x == 0 || y == 0) return 0;

    if(dp[x][y] != -1) return dp[x][y];

    if(s1[x-1] == s2[y-1])
    {
        return dp[x][y] = 1 + solve(x - 1, y - 1, s1, s2, dp);
    }
    if(s1[x] != s2[y])
    {
        return dp[x][y] = max(solve(x, y - 1, s1, s2, dp), solve(x - 1, y, s1, s2, dp));
    }
}

int lcs(int x, int y, string s1, string s2)
{
    // your code here
    vii dp(x, vi(y, -1));
    return solve(x - 1, y - 1, s1, s2, dp);
}

// tabulation
int lcs_tab(int x, int y, string s1, string s2)
{
    // your code here
    vii dp(x+1, vi(y+1, 0));
    for(int i=1; i<= x; i++)
    {
        for(int j=1; j<= y; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[x][y];
}

// tabulation with space optimization
int lcs_SO(int x, int y, string s1, string s2)
{
    // your code here
    vi curr(y+1, 0), prev(y+1, 0);

    for(int i=1; i<= x; i++)
    {
        for(int j=1; j<= y; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                curr[j] = 1 + prev[j-1];
            }
            else 
            {
                curr[j] = max(curr[j-1], prev[j]);
            }
        }
        prev = curr;
    }
    return prev[y];
}

int main()
{

    return 0;
}
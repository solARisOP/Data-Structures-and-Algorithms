#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == t[j])
        return dp[i][j] = 0 + solve(i - 1, j - 1, s, t, dp);

    else
    {
        int in = 1 + solve(i, j - 1, s, t, dp);
        int del = 1 + solve(i - 1, j, s, t, dp);
        int rep = 1 + solve(i - 1, j - 1, s, t, dp);

        return dp[i][j] = min(in, min(del, rep));
    }
}
int editDistance(string s, string t)
{
    // Code here
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
    return solve(s.size() - 1, t.size() - 1, s, t, dp);
}
// memoization right shift index(1 based indexing)
int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 0 + solve(i - 1, j - 1, s, t, dp);

    else
    {
        int in = 1 + solve(i, j - 1, s, t, dp);
        int del = 1 + solve(i - 1, j, s, t, dp);
        int rep = 1 + solve(i - 1, j - 1, s, t, dp);

        return dp[i][j] = min(in, min(del, rep));
    }
}
int editDistance(string s, string t)
{
    // Code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    return solve(s.size(), t.size(), s, t, dp);
}

// tabulation
int editDistance(string s, string t)
{
    // Code here
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= t.size(); j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];

            else
            {
                int in = 1 + dp[i][j - 1];
                int del = 1 + dp[i - 1][j];
                int rep = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(in, min(del, rep));
            }
        }
    }
    return dp[s.size()][t.size()];
}

// tabulation with space optimization
int editDistance(string s, string t)
{
    // Code here
    vector<int> prev(t.size() + 1, 0), curr(t.size()+1, 0);
    for (int j = 0; j <= t.size(); j++)
    {
        prev[j] = j;
    }
    for (int i = 1; i <= s.size(); i++)
    {
        curr[0] = i;
        for (int j = 1; j <= t.size(); j++)
        {
            if (s[i - 1] == t[j - 1])
                curr[j] = 0 + prev[j - 1];

            else
            {
                int in = 1 + curr[j - 1];
                int del = 1 + prev[j];
                int rep = 1 + prev[j - 1];

                curr[j] = min(in, min(del, rep));
            }
        }
        prev = curr;
    }
    return prev[t.size()];
}

int main()
{

    return 0;
}
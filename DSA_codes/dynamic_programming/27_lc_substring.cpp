#include <bits/stdc++.h>
using namespace std;

// tabulation
int lcs(string &s, string &t)
{
	int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n2; j++)
    {
        dp[0][j] = 0;
    }
    int ans =0;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(dp[i][j], ans);

            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

// tabulation with space optimization
int lcs(string &s, string &t)
{
	int n1 = s.length();
    int n2 = t.length();

    vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
    
    int ans =0;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(curr[j], ans);

            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return ans;
}

int main()
{
    
    return 0;
}
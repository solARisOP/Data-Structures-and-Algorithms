#include <bits/stdc++.h>
using namespace std;

string lcs(string s, string t)
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

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n1][n2];
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$'; // dummy string
    }

    int i = n1, j = n2, ind = len - 1;
    // below code came from the analysis of the dp table
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[ind--] = s[i - 1]; // if they match we store the character 
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}
// if the element matches we go upper left daigonal;

int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";

    cout << "The Longest Common Subsequence is "<<lcs(s1, s2);
    
    return 0;
}
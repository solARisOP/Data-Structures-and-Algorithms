#include <bits/stdc++.h>
using namespace std;

// tabulation
string shortestSupersequence(string s, string t) // sol. taken from dp 26 print lcs
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

    int len = n1 + n2 - dp[n1][n2]; // this will be the length of the supersequence string
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += '$'; // dummy string
    }

    int i = n1, j = n2, ind = len - 1;
    // below code came from the analysis of the dp table
    // the sol. is same as print lcs but here we include the elements that we were ignoring in the print lcs code.

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[ind--] = s[i - 1]; // if they match we store the character 
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans[ind--] = s[i - 1];
            i--;
        }
        else
        {
            ans[ind--] = t[j - 1];
            j--;
        }
    }
    // a string can be left with somewhat elements as anyone of the row or column go to 0 from the dp table, so below is the check we do to include the elements from the remaining row or column
    while(i>0) 
    {
        ans[ind--] = s[i - 1];
        i--;
    }

    while(j>0)
    {
        ans[ind--] = t[j - 1];
        j--;
    }

    return ans;
}

int main()
{
    
    return 0;
}
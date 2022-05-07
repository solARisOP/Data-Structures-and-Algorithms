#include <bits/stdc++.h>
using namespace std;

// tabulation
int lcs(string s, string t) // sol. taken from dp 25 longest common subsequences
{
    int n1 = s.length();
    int n2 = t.length();

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
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
            if(s[i-1] == t[j-1]) 
            {
                dp[i][j] = 1 + dp[i-1][j-1]; 
            }
            else
            {
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);         
            }
        }
    }
    
	return dp[n1][n2];
}

int longestPalindromeSubsequence(string s) // sol. taken from dp 28 longest pallindrome subsequences
{
    string t =s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

int minInsertion(string &str)
{
    return str.length() - longestPalindromeSubsequence(str); // if we keep the lps intact, the remaining no. of elements is the no. of insrtions we have to make, to make the string pallindrome 
}

int main()
{
    
    return 0;
}
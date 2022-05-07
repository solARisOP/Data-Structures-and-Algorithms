#include <bits/stdc++.h>
using namespace std;

// tabulation
int lcs(string s, string t) // sol. taken from dp 25 lcs
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

int canYouMake(string &str, string &ptr)
{
    int s1 = str.length(), s2 = ptr.length();
    int ls = lcs(str, ptr);
    return (s2 - ls + s1 - ls); // the first half is the no. of insertions we need to make and secong half is the no. of deletions we need to make, here ls means length of longest common subsequence
}

int main()
{
    
    return 0;
}
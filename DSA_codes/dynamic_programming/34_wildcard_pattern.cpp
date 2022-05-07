#include <bits/stdc++.h>
using namespace std;

// memoization
bool solve(int i, int j, string &p, string &t, vector<vector<int>> &dp)
{
    if(i < 0 && j < 0) return true; // if both are exhausted at once means they matched 
    if(i < 0 && j >= 0) return false; // if the pattern string is exhausted and text string is remaining then it will not match 
    if(j < 0 && i >= 0) // if the pattern string is still remaining and the text string is exhausted
    {
        for (int c = 0; c <= i; c++)
        {
            if(p[c] != '*') return false; // if anyone of them is not star then they did not match
        }
        return true; // if everyone of them is star than they matched
    }
    
    if(dp[i][j] != -1) return dp[i][j];

    if(p[i] == t[j] || p[i] == '?') return dp[i][j] = solve(i-1, j-1, p, t, dp); // if they match or it is question mark both move further 
    else if(p[i] == '*') return dp[i][j] = (solve(i-1, j, p, t, dp) | solve(i, j-1, p, t, dp)); // in one case we check the star for one element and in other we check the star for various elements
    else return dp[i][j] = false;
}

bool wildcardMatching(string p, string t)
{
    int lp = p.length(), lt = t.length();
    vector<vector<int>> dp(lp, vector<int>(lt, -1));
    return solve(lp-1, lt-1, p, t, dp);
}

// memoization by right shifting the indexes by one(1 based indexing).
bool solve(int i, int j, string &p, string &t, vector<vector<int>> &dp)
{
    if(i == 0 && j == 0) return true;  
    if(i == 0 && j > 0) return false;  
    if(j == 0 && i > 0) 
    {
        for (int c = 1; c <= i; c++)
        {
            if(p[c-1] != '*') return false;
        }
        return true;
    }
    
    if(dp[i][j] != -1) return dp[i][j];

    if(p[i-1] == t[j-1] || p[i-1] == '?') return dp[i][j] = solve(i-1, j-1, p, t, dp);
    else if(p[i-1] == '*') return dp[i][j] = (solve(i-1, j, p, t, dp) | solve(i, j-1, p, t, dp)); 
    else return dp[i][j] = false;
}

bool wildcardMatching(string p, string t)
{
    int lp = p.length(), lt = t.length();
    vector<vector<int>> dp(lp+1, vector<int>(lt+1, -1));
    return solve(lp, lt, p, t, dp);
}

// tabulation
bool wildcardMatching(string p, string t)
{
    int lp = p.length(), lt = t.length();
    vector<vector<int>> dp(lp+1, vector<int>(lt+1, 0));
    dp[0][0] = true;
    for (int j = 1; j <= lt; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= lp; i++)
    {
        bool flag = true;
        for (int c = 1; c <= i; c++)
        {
            if(p[c-1] != '*')flag = false; break;
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= lp; i++)
    {
        bool flag = true;
        for (int c = 1; c <= i; c++)
        {
            if(p[c-1] != '*')flag = false; break;
        }
        dp[i][0] = flag;
        for (int j = 1; j <= lt; j++)
        {
            if(p[i-1] == t[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(p[i-1] == '*') dp[i][j] = (dp[i-1][j] | dp[i][j-1]); 
            else dp[i][j] = false;
        }
    }

    return dp[lp][lt];
}

// tabulation with space optimization
bool wildcardMatching(string p, string t)
{
    int lp = p.length(), lt = t.length();
    vector<int> prev(lt+1, 0), curr(lt+1, 0);
    
    prev[0] = true;
    for (int j = 1; j <= lt; j++)
    {
        prev[j] = false;
    }

    for (int i = 1; i <= lp; i++)
    {
        // we are assigning the second base case here because it is required for every row's 0th column
        bool flag = true;
        for (int c = 1; c <= i; c++)
        {
            if(p[c-1] != '*')flag = false; break;
        }
        curr[0] = flag;

        for (int j = 1; j <= lt; j++)
        {
            if(p[i-1] == t[j-1] || p[i-1] == '?') curr[j] = prev[j-1];
            else if(p[i-1] == '*') curr[j] = (prev[j] | curr[j-1]); 
            else curr[j] = false;
        }
        prev = curr;
    }

    return prev[lt];
}

int main()
{
    
    return 0;
}
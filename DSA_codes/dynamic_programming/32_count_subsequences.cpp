#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

// memoization
int solve(int i, int j, string &t, string &s, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1; // if we have exhausted the given string then we have found it in the parent string and we return 1 because it is one of the way
    if (i < 0)
        return 0; // if the parent string in which we are searching is exhausted means we have not found the the given string so we return 0 because it is not the way

    if (dp[i][j] != -1)
        return dp[i][j];

    if (t[i] == s[j])
    {
        int next = solve(i - 1, j - 1, t, s, dp); // here is we are checking for next character 
        int diff_ind = solve(i - 1, j, t, s, dp); //here we will not take this character at present index and search for it in the further indexes.
        return dp[i][j] = (next + diff_ind)%mod; // these are the two possibilites if the characters matches
    }
    else
    {
        return dp[i][j] = (solve(i - 1, j, t, s, dp))%mod; // if the characters doesnot match we look for it in the further indexes
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return solve(lt - 1, ls - 1, t, s, dp);
}

// memoization by right shifting the indexes by one(1 based indexing).
int solve(int i, int j, string &t, string &s, vector<vector<int>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (t[i - 1] == s[j - 1])
    {
        return dp[i][j] = (solve(i - 1, j - 1, t, s, dp) + solve(i - 1, j, t, s, dp))%mod;
    }
    else
    {
        return dp[i][j] = (solve(i - 1, j, t, s, dp))%mod;
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, -1));
    return solve(lt, ls, t, s, dp);
}

// tabulation 
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1, 0));
    for (int i = 0; i <= lt; i++)
    {
        dp[i][0] = 1;
    }
    // we donot require to write the base case for j as we have assigned the vector as 0;

    for (int i = 1; i <= lt; i++)
    {
        for (int j = 1; j <= ls; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j]) % mod;
            }
        }
    }

    return dp[lt][ls];
}

// tabulation with space optimization
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<int> prev(ls + 1, 0), curr(ls + 1, 0);
    prev[0] =1;

    for (int i = 1; i <= lt; i++)
    {
        for (int j = 1; j <= ls; j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                curr[j] = (prev[j - 1] + prev[j]) % mod;
            }
            else
            {
                curr[j] = (prev[j]) % mod;
            }
        }
        prev = curr;
    }

    return prev[ls];

}

// tabulation with 1-d array space optimization
int subsequenceCounting(string &t, string &s, int lt, int ls)
{
    vector<int> prev(ls + 1, 0);
    prev[0] =1;

    for (int i = 1; i <= lt; i++)
    {
        for (int j = ls; j >= 1; j--) // because if we go from 1->ls it will re write elements that we wanna use in for the next elements
        {
            if (t[i - 1] == s[j - 1])
            {
                prev[j] = (prev[j - 1] + prev[j]) % mod;
            }
        }
    }

    return prev[ls];
}

int main()
{
    return 0;
}
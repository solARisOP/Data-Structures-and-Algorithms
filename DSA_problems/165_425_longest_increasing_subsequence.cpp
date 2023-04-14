#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int j, int n, int a[], vii &dp)
{
    if (i == n)
        return 0;
    if (dp[i][j + 1] != -1)
        return dp[i][j + 1];

    int n_take = 0, take = 0;

    if (j == -1 || a[i] > a[j])
        take = 1 + solve(i + 1, i, n, a, dp);
    n_take = solve(i + 1, j, n, a, dp);

    return dp[i][j + 1] = max(take, n_take);
}
int longestSubsequence(int n, int a[])
{
    // your code here
    vii dp(n, vi(n + 1, -1));
    return solve(0, -1, n, a, dp);
}

// tabulation
int longestSubsequence_tab(int n, int a[])
{
    // your code here
    vii dp(n + 1, vi(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int n_take = 0, take = 0;

            if (j == -1 || a[i] > a[j])
                take = 1 + dp[i + 1][i];
            n_take = dp[i + 1][j];

            dp[i][j + 1] = max(take, n_take);
        }
    }
    return dp[0][+1 - 1];
}

// tabulation with space optimization
int longestSubsequence_SO(int n, int a[])
{
    // your code here
    vi curr(n + 1, 0), next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int n_take = 0, take = 0;

            if (j == -1 || a[i] > a[j]) take = 1 + next[i + 1];
            n_take = next[j + 1];

            curr[j + 1] = max(take, n_take);
        }
        next = curr;
    }
    return next[+1 - 1];
}

// diff algo
int longestSubsequence_1d(int n, int a[])
{
    // your code here
    vi dp(n, 1);
    int maxi= -1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if(a[i]>a[prev]) dp[i] = max(dp[i], 1+dp[prev]);
        }
        maxi = max(maxi, dp[i]);
    }
    
    return maxi;
}

// N(log N) method
int longestSubsequence(int n, int a[])
{
    // your code here
    vi temp;
    temp.push_back(a[0]);
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>temp.back())
        {
            temp.push_back(a[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), a[i])- temp.begin();
            temp[ind] = a[i];
        }
    }
    
    return len;
}
int main()
{

    return 0;
}
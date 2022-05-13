#include <bits/stdc++.h>
using namespace std;

int ispallindrome(int i, int j, string s)
{
    while(i<j)
    {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
    // yes a single character is also a pallindrome
}

// memoization
int solve(int i, int n, string str, vector<int> &dp)
{
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int min_cost = 1e9;
    for (int j = i; j < n; j++)
    {
        if(ispallindrome(i, j, str))
        {
            int cost = 1+solve(j+1, n, str, dp); 
            min_cost = min(min_cost, cost); // which ever cost gives us the min. partitions we take up that cost
        }
    }

    return dp[i] = min_cost;    
}

int palindromePartitioning(string str) 
{
    int n = str.length();
    vector<int> dp(n, -1);
    return solve(0, n, str, dp) - 1; // because our code is doing a partition at the last of string thats why we need to subtract 1
}

// tabulation
int palindromePartitioning(string str) 
{
    int n = str.length();
    vector<int> dp(n+1);
    for (int i = n-1; i >= 0; i--)
    {
        int min_cost = 1e9;
        for (int j = i; j < n; j++)
        {
            if(ispallindrome(i, j, str))
            {
                int cost = 1+dp[j+1]; 
                min_cost = min(min_cost, cost); 
            }
        }
        
        dp[i] = min_cost;    
    }
    
    return dp[0] - 1; 
}

int main()
{
    
    return 0;
}
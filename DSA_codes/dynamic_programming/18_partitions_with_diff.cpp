#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);

// memoization
int solve(int s, int i, vector<int> &num, vector<vector<int>> &dp) // sol. taken from dp 17;
{
    // base case is changed because the elements in the array can be 0;
    if(i == 0){
        if(s==0 && num[0]==0)
            return 2;
        if(s==0 || s == num[0])
            return 1;
        return 0;
    }

    if(dp[i][s] != -1) return dp[i][s];

    int pick = 0, n_pick = 0;
    if(num[i] <= s) pick += solve(s-num[i], i-1, num, dp);
    n_pick += solve(s, i-1, num, dp);

    return dp[i][s] = (pick + n_pick)%mod; 
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, -1));
    return solve(tar, n-1, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr) 
{
    int tot_sum =0;

    for (int i = 0; i < n; i++)
    {
        tot_sum+=arr[i];
    }
    if(tot_sum - d < 0 || (tot_sum - d) % 2) return 0;

    int tar = (tot_sum-d)/2; // this came from the derivation of s1-s2 = d;   
    return findWays(arr, tar);    
}

// tabulation
int findWays_tab(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1, 0));

    // these bases cases are because if the array elements contain 0;
    if(num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1;

    
    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= tar; s++)
        {
            int pick = 0;
            if(num[i] <= s) pick = dp[i-1][s-num[i]];
            int n_pick = dp[i-1][s];
            dp[i][s] = (pick + n_pick)%mod;
        }
    }

    return dp[n-1][tar];
}

int countPartitions_tab(int n, int d, vector<int> &arr) 
{
    int tot_sum =0;

    for (int i = 0; i < n; i++)
    {
        tot_sum+=arr[i];
    }
    if(tot_sum - d < 0 || (tot_sum - d) % 2) return 0;

    int tar = (tot_sum-d)/2; // this came from the derivation of s1-s2 = d;   
    return findWays_tab(arr, tar);    
}

// tabulation with space optimization
int findWays_tab1(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> dp(tar+1, 0), curr(tar+1, 0);

    // these bases cases are because if the array elements contain 0;
    if(num[0] == 0) dp[0] = 2;
    else dp[0] = 1;
    if(num[0] != 0 && num[0] <= tar) dp[num[0]] = 1;

    
    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= tar; s++)
        {
            int pick = 0;
            if(num[i] <= s) pick = dp[s-num[i]];
            int n_pick = dp[s];
            curr[s] = (pick + n_pick)%mod;
        }
        dp = curr;
    }

    return dp[tar];
}

int countPartitions_tab1(int n, int d, vector<int> &arr) 
{
    int tot_sum =0;

    for (int i = 0; i < n; i++)
    {
        tot_sum+=arr[i];
    }
    if(tot_sum - d < 0 || (tot_sum - d) % 2) return 0;

    int tar = (tot_sum-d)/2; // this came from the derivation of s1-s2 = d;   
    return findWays_tab1(arr, tar);    
}


int main()
{
    
    return 0;
}
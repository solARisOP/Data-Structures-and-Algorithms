#include <bits/stdc++.h>
using namespace std;


// tabulation
int minSubsetSumDifference(vector<int>& arr, int n) // tabulation taken from dp 14 
{
    int total_sum =0;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    
    int k = total_sum;

	vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true; // because if target is 0 then its true;
    }
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool n_take = dp[i - 1][tar];

            bool take = false;
            if (tar >= arr[i])
                take = dp[i - 1][tar - arr[i]];

            dp[i][tar] = take | n_take;
        }
    }
    int mini = 1e9;

    for (int s1 = 0; s1 <= total_sum/2; s1++) // here we are checking upto half of the total sum because if we check for the full the answer will not vary as the other half will be same as previous half

    {
        if(dp[n-1][s1] == true)
        {
            mini = min(mini, abs((total_sum-s1)-s1));
        }
    }
    
    return mini;
}

// tabulation with space optimization
int minSubsetSumDifference(vector<int>& arr, int n) // tabulation taken from dp 14 
{
    int total_sum =0;

    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }
    
    int k = total_sum;

	vector<int> dp(k + 1), curr(k+1);

    dp[0] = curr[0] = true;
    if(arr[0]<=k) dp[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int tar = 1; tar <= k; tar++)
        {
            bool n_take = dp[tar];

            bool take = false;
            if (tar >= arr[i])
                take = dp[tar - arr[i]];

            curr[tar] = take | n_take;
        }
        dp = curr;
    }

    int mini = 1e9;

    for (int s1 = 0; s1 <= total_sum/2; s1++) // here we are checking upto half of the total sum because if we check for the full the answer will not vary as the other half will be same as previous half

    {
        if(dp[s1] == true)
        {
            mini = min(mini, abs((total_sum-s1)-s1));
        }
    }
    
    return mini;
} 

int main()
{
    
    return 0;
}
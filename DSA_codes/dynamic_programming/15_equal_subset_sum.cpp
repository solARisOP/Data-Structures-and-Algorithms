#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k, vector<int> &arr) // space optimization solution from previous question
{
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

    return dp[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int t_sum =0;
    for (int i = 0; i < n; i++)
    {
        t_sum+=arr[i];
    }

    if(t_sum%2 != 0) return false;

    int target = t_sum/2;
    return solve(n-1, target, arr);
}


int main()
{
    
    return 0;
}
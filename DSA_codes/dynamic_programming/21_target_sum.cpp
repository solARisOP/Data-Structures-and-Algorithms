#include <bits/stdc++.h>
using namespace std;

// tabulation with space optimization
int findWays_tab1(vector<int> &num, int tar) // sol. reffered from dp 18, its exactly the same problem they have just changed the language there it was s1-s2 =d, here it is sum of positive and negative elements equal to target
{
    int n = num.size();
    vector<int> dp(tar+1, 0), curr(tar+1, 0);

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
            curr[s] = (pick + n_pick);
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

    int tar = (tot_sum-d)/2; 
    return findWays_tab1(arr, tar);    
}

int targetSum(int n, int target, vector<int>& arr)
{
    return countPartitions_tab1(n, target, arr);
}

int main()
{
    
    return 0;
}
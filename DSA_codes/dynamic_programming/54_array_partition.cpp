#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int n, vector<int> &num, int k, vector<int> &dp)
{
    if(i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int sum = 0, max_ele = num[i], max_sum = -1e9;;
    for (int j = i, c = 0; j <  n; j++)
    {
        c++;
        if(c>k) break;
        max_ele = max(max_ele, num[j]);
        sum =(max_ele*c)+ solve(j+1, n, num, k, dp);
        max_sum = max (max_sum, sum);
    }
    
    return dp[i] = max_sum;
}

int maximumSubarray(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return solve(0, n, num, k, dp);
}

// tabulation
int maximumSubarray_tab(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n+1, 0);
    for (int i = n-1; i >= 0; i--)
    {
        int sum = 0, max_ele = num[i], max_sum = -1e9;;
        for (int j = i, c = 0; j < n; j++)
        {
            c++;
            if(c>k) break;
            max_ele = max(max_ele, num[j]);
            sum =(max_ele*c)+ dp[j+1];
            max_sum = max (max_sum, sum);
        }

        dp[i] = max_sum;
    }
    
    return dp[0];
}

int main()
{
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    cout<<maximumSubarray_tab(num, 3);

    return 0;
}
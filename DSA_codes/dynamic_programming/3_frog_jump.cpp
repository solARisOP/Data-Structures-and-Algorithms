#include <bits/stdc++.h>
using namespace std;

/*memoization*/
// int f(int n, vector<int> &heigths, vector<int> &dp)
// {
//     if(n == 0) return 0;
    
//     if(dp[n] != -1) return dp[n];
//     int l = f(n-1, heigths, dp) + abs(heigths[n] - heigths[n-1]);
//     int r = INT_MAX;
//     if(n>1) r = f(n-2, heigths, dp) + abs(heigths[n] - heigths[n-2]);

//     dp[n] = min(l,r);
//     return min(l,r);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n, -1);
//     return f(n-1, heights, dp);
// }

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int l = prev1 + abs(heights[i] - heights[i-1]);
        int r = INT_MAX;
        if(i>1) r = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(l,r);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
    
}
int main()
{
    
    return 0;
}
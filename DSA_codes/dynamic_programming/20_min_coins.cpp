#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int x, vector<int> &num, vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(x%num[i] == 0) return x/num[i]; // because if it perfectly divides by the target then we can use it as many times until target becomes 0
        else return 1e9;
    }

    if(dp[i][x] != -1) return dp[i][x];

    int n_pick = 0 + solve(i-1, x, num, dp);
    int pick = 1e9;
    if(num[i]<=x)pick = 1 + solve(i, x-num[i], num, dp); // we are standing at the same index because in multiple uses or infinite supply we may use this element many times.

    return dp[i][x] = min(pick, n_pick);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = solve(n-1, x, num, dp);
	if(ans>= 1e9) return -1;
	return ans;
}

// tabulation
int minimumElements_tab(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    for (int T = 0; T <= x; T++)
    {
        if(T%num[0] == 0) dp[0][T] = T/num[0];
        else dp[0][T] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= x; T++)
        {
            int n_pick = 0 + dp[i-1][T];
            int pick = 1e9;
            if(num[i]<=T)pick = 1 + dp[i][T-num[i]];
            dp[i][T] = min(pick, n_pick);
        }
    }
    
    int ans = dp[n-1][x];
	if(ans>= 1e9) return -1;
	return ans;
}

// tabulation with space optimization
int minimumElements_tab1(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x+1, 0), curr(x+1, 0);

    for (int T = 0; T <= x; T++)
    {
        if(T%num[0] == 0) prev[T] = T/num[0];
        else prev[T] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= x; T++)
        {
            int n_pick = 0 + prev[T];
            int pick = 1e9;
            if(num[i]<=T)pick = 1 +curr[T-num[i]]; // because we are standing at the same index in the memoization thats why we use curr array's element
            curr[T] = min(pick, n_pick);
        }
        prev = curr;
    }
    
    int ans = prev[x];
	if(ans>= 1e9) return -1;
	return ans;
}

int main()
{
    
    return 0;
}
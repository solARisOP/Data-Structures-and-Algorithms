#include <bits/stdc++.h>
using namespace std;

// memoization 
int solve(int last, int d, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(d == 0)
    {
        int maxi =0;
        for (int i = 0; i <= 2; i++)
        {
            if(i!=last)
            {
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[d][last] != -1) return dp[d][last];

    int maxi =0;
    for (int i = 0; i <= 2; i++)
    {
        if(i!=last)
        {
            int p = points[d][i] + solve(i, d-1, points, dp);
            maxi = max(maxi, p);
        }
    }
    return dp[d][last] = maxi;
    
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(3, n-1, points, dp);
}

// tabulation
int ninjaTraining_tab(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][3]));

    for (int days = 1; days < n; days++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[days][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task!=last)
                {
                    int p = points[days][task] + dp[days-1][task];
                    dp[days][last] = max(dp[days][last], p);
                }
            }   
        }   
    }
    return dp[n-1][3];
}    

// tabulation with space optimisation
int ninjaTraining_tab_c(int n, vector<vector<int>> &points)
{
    vector<int> dp(4,-1);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][2], points[0][0]);
    dp[2] = max(points[0][1], points[0][0]);
    dp[3] = max(points[0][1], max(points[0][2], points[0][3]));

    for (int days = 1; days < n; days++)
    {
        vector<int> temp(4,-1);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if(task!=last)
                {
                    int p = points[days][task] + dp[task]; // we are using dp here for computing*
                    temp[last] = max(temp[last], p);
                }
            }   
        }
        dp = temp;  // we are storing here for use it for computing next time* 
    }
    return dp[3];
}    

int main()
{
    vector<vector<int>> points = {{10, 40, 70}, 
                                  {20, 50, 80},
                                  {30, 60, 90}};

    cout<<ninjaTraining_tab_c(3, points);
    return 0;
}
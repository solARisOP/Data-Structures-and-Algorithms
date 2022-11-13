#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 9;

int solve(int ques_curr, int ques, int corr, int ans, int k, int conce, int points, vector<vector<int>> &dp)
{
    if (conce == k)
    {
        points = points* 2;
        conce = 0;
    }
    if (ques_curr == ques)
    {
        if (corr == ans)
        {
            // cout<<points<<endl;
            return points;
        }   
        else
        {
            // cout<<INT_MAX<<endl;
            return INT_MAX;
        }

            
    }

    if (dp[ques_curr][corr] != -1)
        return dp[ques_curr][corr];

    int a = solve(ques_curr + 1, ques, corr + 1, ans, k, conce + 1, points + 1, dp);
    int b = solve(ques_curr + 1, ques, corr, ans, k, 0, points, dp);
    cout<<a<<" , "<<b<<endl;
    return dp[ques_curr][corr] = min(a, b);
}

int func(int n, int m, int k)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, n, 0, m, k, 0, 0, dp);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << func(n, m, k);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// memoization
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp); // the first parameter is the difference of cuts made in the last call and it gives the current cost(current length of the stick)

        mini = min(cost, mini);
    }

    return dp[i][j] = mini;  
}

int cost(int n, int c, vector<int> &cuts)
{
    sort(cuts.begin(), cuts.end()); // because if we sort it it will be independently solve the further cases and we need not to worry
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
    return solve(1, c, cuts, dp);
}

// tabulation
int cost(int n, int c, vector<int> &cuts)
{
    sort(cuts.begin(), cuts.end()); 
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0)); 

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if(i>j) continue; // because the partition is running from i -> j
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];

                mini = min(cost, mini);
            }

            dp[i][j] = mini;
        }
    }
    
    return dp[1][c];
}

int main()
{
    
    return 0;
}
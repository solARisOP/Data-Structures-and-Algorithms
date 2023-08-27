#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vvi dp(N, vi(N, 0));
    for(int i=N-1; i>0; i--)
    {
        for(int j = i+1; j<N; j++)
        {
            int mini = INT_MAX;
            for(int ind = i+1; ind <=j; ind++)
            {
                int x = arr[i-1]*arr[ind-1]*arr[j] + dp[i][ind-1] + dp[ind][j];
                mini = min(x, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // need not to write the base case because base case is 0 and originally declared is also 0

    for (int i = N-1; i > 0; i--)
    {
        for (int j = i+1; j < N; j++) // j starts from i+1 because j cannot be at left of i so practicaly j should be at right of i because of k, so we start j at i+1 so it can be at right of i
        {
            int mini = 1e9;
            for (int k = i; k < j; k++) 
            {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]; 
                if(steps < mini) mini = steps;
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
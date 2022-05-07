#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if(i == j) return 0; // when the i and j point at same then it means it is a single matrix and its operations for multiplications will be 0

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++) // k is for the partition
    {
        int steps = arr[i-1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp); // the first parameter it is derived from an analysis is for the final m*m, second parameter is for the left partition and third is for the right partition
        if(steps < mini) mini = steps;
    }

    return dp[i][j] = mini;    
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solve(1, N-1, arr, dp); // starts from 1 because, if started from 0 it will be out of bound for row parameter. i is col and i-1 is row or vice versa
}

int main()
{
    
    return 0;
}
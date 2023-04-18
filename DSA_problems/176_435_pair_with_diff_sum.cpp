#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int i, int prev, int n, int k, int arr[], vii &dp)
{
    if (i == n)
        return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int take = 0, n_take = 0;
    if (prev == -1)
        take = solve(i + 1, i, n, k, arr, dp);
    else if (abs(arr[prev] - arr[i]) < k)
        take = (arr[i] + arr[prev]) + solve(i + 1, -1, n, k, arr, dp);

    n_take = solve(i + 1, prev, n, k, arr, dp);

    return dp[i][prev + 1] = max(take, n_take);
}
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Your code goes here
    sort(arr, arr + N);
    vii dp(N, vi(N + 1, -1));
    return solve(0, -1, N, K, arr, dp);
}

// nlogn with constant space solution
int maxSumPairWithDifferenceLessThanK_SO(int arr[], int N, int K)
{
    // Your code goes here
    sort(arr, arr + N);
    int sum = 0;
    for(int i = N-1; i>0; i--)
    {
        if(arr[i] - arr[i-1]<K) sum+=0; i--;
    }

    return sum;
}


int main()
{

    return 0;
}
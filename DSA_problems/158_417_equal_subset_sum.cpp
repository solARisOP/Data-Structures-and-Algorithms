#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int solve(int i, int sum, int total, int arr[], vector<vector<int>> &dp)
{
    if (sum * 2 > total)
        return 0;
    if (sum * 2 == total)
        return 1;
    if (i < 0)
    {
        if (sum * 2 == total)
            return 1;
        else
            return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    int take = solve(i - 1, sum + arr[i], total, arr, dp);
    int n_take = solve(i - 1, sum, total, arr, dp);

    return dp[i][sum] = (take | n_take);
}
int equalPartition(int N, int arr[])
{
    // code here
    int total = 0;
    for (int i = 0; i < N; i++)
        total += arr[i];
    vector<vector<int>> dp(N, vector<int>((total / 2) + 1, -1));
    return solve(N - 1, 0, total, arr, dp);
}

int main()
{
    int arr[] = {1, 3, 5};
    cout << equalPartition(3, arr);
    return 0;
}
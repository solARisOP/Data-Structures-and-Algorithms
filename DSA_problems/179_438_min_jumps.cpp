#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int i, int n, int arr[], vi &dp)
{
    if (i >= n - 1)
        return 0;
    if (dp[i] != INT_MIN)
        return dp[i];
    if (arr[i] == 0)
        return -1;

    int mini = INT_MAX;
    for (int j = 1; j <= arr[i]; j++)
    {
        int jump = 1 + solve(i + j, n, arr, dp);
        if (jump != 0)
            mini = min(jump, mini);
    }
    if (mini == INT_MAX)
        return dp[i] = -1;
    else
        return dp[i] = mini;
}
int minJumps(int arr[], int n)
{
    // Your code here
    vi dp(n, INT_MIN);
    return solve(0, n, arr, dp);
}

// tabulation
int minJumps(int arr[], int n)
{
    // Your code here
    vi dp(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0)
            dp[i] = -1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= arr[i]; j++)
        {
            int jump = 1;
            if (i + j >= n - 1)
                jump = 1;
            else
                jump = 1 + dp[i + j];
            if (jump != 0)
                mini = min(jump, mini);
        }
        if (mini == INT_MAX)
            dp[i] = -1;
        else
            dp[i] = mini;
    }
    return dp[0];
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minJumps(arr, n);

    priority_queue <int> pq;
    return 0;
}
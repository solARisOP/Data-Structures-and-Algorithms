#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

// memoization
int solve(int egg, int flr, vii &dp)
{
    if (egg == 1)
        return flr;
    if (flr == 1 || flr == 0)
        return flr;
    if (dp[egg][flr] != -1)
        return dp[egg][flr];

    int mini = INT_MAX;

    for (int k = 1; k <= flr; k++)
    {
        int temp = 1 + max(solve(egg - 1, k - 1, dp), solve(egg, flr - k, dp));
        mini = min(mini, temp);
    }

    return dp[egg][flr] = mini;
}
int eggDrop(int egg, int flr)
{
    // your code here
    vii dp(egg + 1, vi(flr + 1, -1));
    return solve(egg, flr, dp);
}

// memoization optimization
int solve_MO(int egg, int flr, vii &dp)
{
    if (egg == 1)
        return flr;
    if (flr == 1 || flr == 0)
        return flr;
    if (dp[egg][flr] != -1)
        return dp[egg][flr];

    int mini = INT_MAX;

    for (int k = 1; k <= flr; k++)
    {
        int low, high;

        if (dp[egg - 1][k - 1] != -1)
            low = dp[egg - 1][k - 1];
        else
            low = solve(egg - 1, k - 1, dp);

        if (dp[egg - 1][k - 1] != -1)
            high = dp[egg][flr - k];
        else
            high = solve(egg, flr - k, dp);

        int temp = 1 + max(low, high);
        mini = min(mini, temp);
    }

    return dp[egg][flr] = mini;
}

int eggDrop_MO(int egg, int flr)
{
    // your code here
    vii dp(egg + 1, vi(flr + 1, -1));
    return solve(egg, flr, dp);
}

// tabulation
int eggDrop_tab(int egg, int flr)
{
    // your code here
    vii dp(egg + 1, vi(flr + 1, 0));
    for (int e = 1; e <= egg; e++)
    {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }
    for (int f = 1; f <= flr; f++)
    {
        dp[1][f] = f;
    }

    for (int e = 2; e <= egg; e++)
    {
        for (int f = 2; f <= flr; f++)
        {
            int mini = INT_MAX;

            for (int k = 1; k <= f; k++)
            {
                int temp = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);
                mini = min(mini, temp);
            }
            dp[e][f] = mini;
        }
    }
    return dp[egg][flr];
}

// space optimization
int eggDrop_SO(int egg, int flr)
{
    // your code here
    vi curr(flr + 1, 0), prev(flr + 1, 0);
    for (int f = 1; f <= flr; f++)
    {
        curr[f] = f;
        prev[f] = f;
    }

    for (int e = 2; e <= egg; e++)
    {
        for (int f = 2; f <= flr; f++)
        {
            int mini = INT_MAX;

            for (int k = 1; k <= f; k++)
            {
                int temp = 1 + max(prev[k - 1], curr[f - k]);
                mini = min(mini, temp);
            }
            curr[f] = mini;
        }
        prev = curr;
    }
    return curr[flr];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int coinChange(vector<int> &coins, int amount)
{
    if (!amount)
        return 0;
    int n = coins.size();
    vi prev(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int n_pick = 0 + prev[j];
            int pick = 1e9;
            if (j >= coins[i])
                pick = 1 + curr[j - coins[i]];

            curr[j] = min(pick, n_pick);
        }
        prev = curr;
    }

    return prev[amount] == 1e9 ? -1 : prev[amount];
}

int main()
{
    
    return 0;
}
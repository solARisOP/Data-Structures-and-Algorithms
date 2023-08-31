#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    sort(begin(cuts), end(cuts));
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    vvi dp(c + 2, vi(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = 1e9;

            for (int ind = i; ind <= j; ind++)
            {
                mini = min(mini, cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]);
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
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int profit = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++)
    {
        if (prices[i] > mini)
            profit = max(profit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }

    return profit;
}

int main()
{

    return 0;
}
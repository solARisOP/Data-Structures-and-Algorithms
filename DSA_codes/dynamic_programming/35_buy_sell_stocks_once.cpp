#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int mini = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - mini; // selling the stock
        profit = max(cost, profit); // keeping track of the max profit

        mini = min(mini, prices[i]); // keeping track of the minimum price so we can make max profit
    }
    return profit;
}

int main()
{
    
    return 0;
}
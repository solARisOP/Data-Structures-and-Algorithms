#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int n = INT_MAX,profit =0;
    for (int i = 0; i < prices.size(); i++)
    {
        if(prices[i]<n)
        {
            n = prices[i];
        }
        if(prices[i]>n)
        {
            if(profit < (prices[i]- n))
            {
                profit = prices[i]-n;
            }    
        }
    }  
    return profit;
}

int main()
{
    vector<int> v = {4,6,2,6,7,1};
    cout<<maxProfit(v);
    return 0;
}
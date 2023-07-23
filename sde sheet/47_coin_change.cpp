#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int findMinimumCoins(int amount)
{
    // Write your code here
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int cnt = 0;
    int i = 8;
    while (i >= 0)
    {
        if (amount >= coins[i])
        {
            amount -= coins[i];
            cnt++;
        }
        else
            i--;
    }
    return cnt;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

int mod = 1e9 + 7;
long long solve(int n, vector<int> &dp)
{
    if (n == 3)
        return 4;
    if (n == 2)
        return 2;
    if (n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (solve(n - 1, dp) + (n - 1) * solve(n - 2, dp)) % mod;
}
int countFriendsPairings(int n)
{
    // code here
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}

int main()
{

    return 0;
}
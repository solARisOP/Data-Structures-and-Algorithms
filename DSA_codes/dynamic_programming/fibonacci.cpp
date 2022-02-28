#include <bits/stdc++.h>
using namespace std;

/*******************memoization********************/

unsigned long long dp[100000];

unsigned long long fib(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] = fib(n-1) + fib(n-2);

    return dp[n];
}

int main()
{
    fill(dp, dp+100000, -1);
    int n;
    cin>>n;
    cout<<fib(n);

    return 0;
}

/*******************tabulation********************/

// long long int fib(int n)
// {
//     long long int dp[n+1];
//     dp[1] = 0;
//     dp[2] = 1;

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = dp[i-1] + dp[i-2];
//     }
    
//     return dp[n];
// }

// int main()
// {
    
//     int n;
//     cin>>n;
//     cout<<fib(n);

//     return 0;
// }

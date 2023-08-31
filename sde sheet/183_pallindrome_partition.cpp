#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>
bool ispallindrome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
    // yes a single character is also a pallindrome
}
int palindromicPartition(string str)
{
    // code here
    int n = str.length();
    vi dp(n + 1);

    for (int i = n - 1; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int ind = i; ind < n; ind++)
        {
            if (ispallindrome(i, ind, str))
                mini = min(mini, 1 + dp[ind + 1]);
        }

        dp[i] = mini;
    }

    return dp[0] - 1;
}

int main()
{

    return 0;
}
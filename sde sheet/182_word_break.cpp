#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    unordered_map<string, bool> mpp;
    for (string it : wordDict)
        mpp[it] = 1;
    vi dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        string temp = "";
        for (int ind = i; ind < s.size(); ind++)
        {
            temp.push_back(s[ind]);
            if (mpp[temp] && dp[ind + 1])
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}

int main()
{

    return 0;
}
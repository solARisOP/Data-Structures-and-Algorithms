#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int lengthOfLongestSubstring(string s)
{
    if (!s.length())
        return 0;
    unordered_map<char, int> mpp;
    int n = s.length();
    int maxi = 1;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(s.at(i)) != mpp.end())
        {
            maxi = max(maxi, i - x);
            x = max(x, mpp[s[i]] + 1);
        }
        mpp[s[i]] = i;
    }

    maxi = max(maxi, n - x);

    return maxi;
}

int main()
{
    
    return 0;
}
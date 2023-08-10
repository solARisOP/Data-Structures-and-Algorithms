#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int check(string s, int l, int r)
{
    if (s.length() < 1 || l > r)
        return 0;
    while (l >= 0 && r < s.length() && s[l] == s[r])
    {
        l--;
        r++;
    }

    return r - l - 1;
}

string longestPalindrome(string s)
{
    int n = s.length();
    int mid = 0;
    int maxi = 0;
    int start = 0;
    while (mid < n)
    {
        int a = check(s, mid, mid);
        int b = check(s, mid, mid + 1);
        if (maxi < max(a, b))
        {
            maxi = max(a, b);
            start = mid - (maxi - 1) / 2;
        }

        mid++;
    }
    return s.substr(start, maxi);
}

int main()
{

    return 0;
}
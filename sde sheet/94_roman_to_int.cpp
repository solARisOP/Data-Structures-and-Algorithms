#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int solve(char c)
{
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c == 'D')
        return 500;
    else
        return 1000;
}

int romanToInt(string s)
{
    if (s.length() == 1)
        return solve(s[0]);
    int n = s.length();
    int ans = 0;
    int i = n - 1;
    for (i; i > 0; i--)
    {
        int a = solve(s[i]);
        int b = solve(s[i - 1]);
        if (a > b)
        {
            ans += (a - b);
            i--;
            continue;
        }
        else
            ans += a;
    }
    if (!i)
        ans += solve(s[0]);
    return ans;
}

int main()
{
    
    return 0;
}
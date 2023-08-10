#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

string solve(int x)
{
    if (x == 1)
        return "1";
    string s = solve(x - 1);
    int n = s.length();
    int i = 0, j = 0;
    string ans = "";
    while (j < n)
    {
        if (s[i] == s[j])
            j++;
        else
        {
            char c = (j - i) + '0';
            ans += c;
            ans += s[i];
            i = j;
        }
    }
    char c = (j - i) + '0';
    ans += c;
    ans += s[i];

    return ans;
}

string countAndSay(int n)
{
    return solve(n);
}

int main()
{
    string s = "2";
    cout<<s[0]-'0';
    return 0;
}
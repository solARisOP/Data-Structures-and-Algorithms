#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool ispallindrome(int i, int n, string &s)
{
    while (i <= n)
    {
        if (s[i] != s[n])
            return 0;
        i++, --n;
    }

    return 1;
}
void solve(int ind, string &s, vector<string> &part, vector<vector<string>> &ans)
{

    if (ind == s.length())
    {
        ans.push_back(part);
        return;
    }
    int n = s.length();
    for (int i = ind; i < n; i++)
    {
        if (ispallindrome(ind, i, s))
        {
            part.push_back(s.substr(ind, i - ind + 1));
            solve(i + 1, s, part, ans);
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> part;
    solve(0, s, part, ans);

    return ans;
}

int main()
{

    return 0;
}
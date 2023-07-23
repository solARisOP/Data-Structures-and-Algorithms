#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(string &s, string &ans)
{
    if(ans.length() == s.length())
    {
        cout<<ans<<" ";
        return;
    }

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]!='0')
        {
            char c = s[i];
            ans.push_back(s[i]);
            s[i] = '0';
            solve(s,ans);
            s[i]= c;
            ans.pop_back();
        }
    }
}

int main()
{
    string s = "12345"; 
    vi vis(s.length(), 0);
    string ans = "";
    solve(s, ans);
    return 0;
}
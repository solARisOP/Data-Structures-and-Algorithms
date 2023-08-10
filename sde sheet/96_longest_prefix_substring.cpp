#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    if (n == 1) return strs[0];

    int scan_s = INT_MAX;
    for (int i = 0; i < strs.size(); i++) scan_s = min<int>(scan_s, strs[i].size());

    if (!scan_s) return "";
    int sc = 0;
    while (sc < scan_s)
    {
        int fl = 1;
        for (int i = 0; i < n; i++)
        {
            if (strs[i][sc] != strs[0][sc])
            {
                fl = 0;
                break;
            }
        }
        if (!fl) break;
        sc++;
    }
    
    return strs[0].substr(0, sc);
}

int main()
{
    string a = "abcabcabc", b = "cabcabca";
    if(a.find(b) != string::npos) cout<<1;
    else cout<<0;
    // cout<<a.find(b)<<endl;
    return 0;
}
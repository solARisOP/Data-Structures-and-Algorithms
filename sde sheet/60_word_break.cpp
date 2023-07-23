#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(int ind, unordered_map<string, int> &mpp, string &s, string &str, vector<string> &ans)
{
    if (ind == s.size())
    {
        ans.push_back(str);
        return;
    }

    if (ind)
        str += ' ';
    int n = s.size();
    for (int i = ind; i < n; i++)
    {
        string test = s.substr(ind, i - ind + 1);
        if (mpp[test])
        {
            str += test;
            solve(i + 1, mpp, s, str, ans);
            int ns = test.size();
            str.erase(str.end()-ns, str.end());
        }
    }
    if(ind) str.pop_back();
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_map<string, int> mpp;
    int n = dictionary.size();
    for (int i = 0; i < n; i++)
    {
        mpp[dictionary[i]] = 1;
    }
    vector<string> ans;
    string str;
    solve(0, mpp, s, str, ans);
    return ans;
}

int main()
{
    vector<string> dict = {"god", "is", "now", "no", "where", "here"};
    string s = "godisnowherenowhere";
    vector<string> ans = wordBreak(s, dict);
    for(auto it : ans) cout<<it<<endl;
    return 0;
}
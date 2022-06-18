#include <bits/stdc++.h>
using namespace std;

string makeip(vector<string> t)
{
    string g;
    for (int i = 0; i < t.size(); i++)
    {
        g+=t[i];
        if(i == t.size()-1) break;
        g+='.';
    }
    cout<<g<<endl;
    return g;
}

vector<string> solve(int i, vector<string> &ans, vector<string> &in, string &s)
{
    if(i == s.size()) 
    {

        ans.push_back(makeip(in));
        return ans;
    }

    in.push_back("");
    for (int j = i; j < (s.size() && i+3); j++)
    {
        in.pop_back();
        in.push_back(s.substr(i,j-i+1));
        return solve(j+1, ans, in, s);
    }    
}

vector<string> genIp(string &s) 
{
    vector<string> ans, in;
    return solve(0, ans, in, s);
}

int main()
{
    string s = "25525511135";
    vector<string> v(genIp(s));
    cout<<endl;
    for (auto it : v)
    {
        cout<<it<<endl;
    }
    
    return 0;
}
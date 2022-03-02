#include <bits/stdc++.h>
using namespace std;

// recurssive approach
void solve(vector<string>& v, string s, int i)
{
    if(i >= s.length())
    {
        v.push_back(s);
        return ;
    }

    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        solve(v, s, i+1);
        swap(s[i], s[j]);
    }
    return;
}

vector<string>find_permutation(string S)
{
    
    vector<string> v;
    solve(v, S, 0);
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    string s = "abc";
    vector<string> v = find_permutation(s);
    for(auto i : v)
    {
        cout<<i<<" ";
    }    
    return 0;
}
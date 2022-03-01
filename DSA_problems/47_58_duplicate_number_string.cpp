#include <bits/stdc++.h>
using namespace std;

void duplicates(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second >1) cout<<it.first<<" ";
    }
}

int main()
{
    string s = "fgtrewsftffdgt";
    duplicates(s);

    return 0;
}
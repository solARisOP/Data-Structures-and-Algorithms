#include <bits/stdc++.h>
using namespace std;

void printsubsequence(vector<string> &v, string s, string o, int i)
{
    if(i >= s.length())
    {
        if(o.length()>=1)
        {
            v.push_back(o);
            return;
        }
        else return;
    }

    printsubsequence(v,s,o,i+1);

    o.push_back(s[i]);
    printsubsequence(v,s,o,i+1);
    return;
}

int main()
{
    string s = "abc";
    vector<string> v;
    string o;
    printsubsequence(v, s, o, 0);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    return 0;
}
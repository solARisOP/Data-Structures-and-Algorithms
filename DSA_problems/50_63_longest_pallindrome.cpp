#include <bits/stdc++.h>
using namespace std;

int check(string s, int l, int r)
{
    if(s.length()<=0 || l>r) return 0;
    while(l>=0 && r<s.length() && s[l] == s[r])
    {
        l--;
        r++;
    }

    return r-l-1;
}

string longestPalin (string S)
{
    int start =0, end =0, maxl = INT_MIN;
    for (int i = 0; i < S.length(); i++)
    {
        int l1 = check(S, i, i);
        int l2 = check(S, i, i+1);
        int len = max(l1, l2);
        if(maxl<len)
        {
            start = i -(len - 1)/2;
            maxl = len;
        }
    }
    return S.substr(start, maxl);
}



int main()
{
    string S = "aaaabbaa";
    return 0;
}
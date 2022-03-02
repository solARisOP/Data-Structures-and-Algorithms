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
    int start =0, end =0;
    for (int i = 0; i < S.length(); i++)
    {
        int l1 = check(S, i, i);
        int l2 = check(S, i, i+1);
        int len = max(l1, l2);
        if(end - start < len)
        {
            
            start = i -(len - 1)/2;
            end = i + (len)/2;
        }
    }
    return S.substr(start, end +1);
}

int main()
{
    
    return 0;
}
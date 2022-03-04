#include <bits/stdc++.h>
using namespace std;

int check(char c)
{
    if(c == 'I')return 1;
    if(c == 'V')return 5;
    if(c == 'X')return 10;
    if(c == 'L')return 50;
    if(c == 'C')return 100;
    if(c == 'D')return 500;
    return 1000;
}

int romanToDecimal(string &str) 
{
    int ans=0, t=0;
    int len = str.size();
    for (int i = len-1; i >= 0; i--)
    {
        int n = check(str[i]);
        ans = (n>=t) ? ans+n : ans-n;
        t=n;
    }
    return ans;
}

int main()
{
    string s = "MMMCDIX";
    cout<<romanToDecimal(s);
    return 0;
}
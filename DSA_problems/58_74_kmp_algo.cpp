#include <bits/stdc++.h>
using namespace std;

int lps(string s) 
{
    if(s.size()<=1) return 0;
	string p = s.substr(1);
    s = s.substr(0, s.size()-1);
    while(s != p)
    {
        s = s.substr(0, s.size()-1);
        p = p.substr(1, p.size()-1);
    }
    return s.size();
}
int main()
{
    string s = "ababa";
    cout<<lps(s);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int findSubString(string str)
{
    int n = str.size();
    set<char> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(str[i]);
    }
    int k = s.size();
        
}

int main()
{
    string s = "daugdugdgubgddgggdgdgdgggggggggggggggggggggggd";
    cout<<findSubString(s)<<endl;
    return 0;
}
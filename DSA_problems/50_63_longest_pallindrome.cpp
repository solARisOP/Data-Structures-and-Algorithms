#include <bits/stdc++.h>
using namespace std;

bool checkpallindrome(string s, int st, int e)
{
    string p = s;
    reverse(s.begin()+st, s.begin()+e);
    if(p == s)
        return true;
    return false;
}

string longestPalin (string S) 
{
    if(checkpallindrome(S, 0, S.size())) return S;
    
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = S.size()-1; j >= i; j--)
        {
            if(checkpallindrome(S, i, j+1))
            {
                // string P = S
                S.erase(S.begin(), S.begin()+i);
                S.erase(S.begin()+j+1, S.end());
                return S;
            }
        }   
    }
    string p;
    p.push_back(S[0]);
    return p;
}

int main()
{
    string S = "aaaabbaa";
    cout<<longestPalin(S);
    return 0;
}
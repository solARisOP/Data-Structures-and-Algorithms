#include <bits/stdc++.h>
using namespace std;


int isPalindrome(string S)
{
    for(int i=0; i<S.length(); i++)
    {
        if(S[i] != S[S.length()-1-i])
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    string s = "22022022";
    cout<<isPalindrome(s);    
    return 0;
}
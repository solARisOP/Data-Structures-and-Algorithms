#include <bits/stdc++.h>
using namespace std;

int counts(string s)
{
    int c0 =0, c1=0, c=0;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0')
        {
            c0++;
        }
        else if(s[i] == '1')
        {
            c1++;
        }
        if(c0 == c1) // if count is same initial count wiil be incremented
        {
            c++;
        }
    }
    
    if(c1 != c0)
    {
        return -1;
    }
    return c;

}

int main()
{
    string s = "010011";

    cout<<counts(s);
    return 0;
}
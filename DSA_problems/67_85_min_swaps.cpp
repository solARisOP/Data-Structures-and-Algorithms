#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string s)
{
    int n = s.length();

    int open =0, close=0, unbalanced =0, swap =0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '[')
        {
            open++;
            if(unbalanced>0)
            {
                swap+=unbalanced;
            }
        }
        else
        {
            close++;
        }
        unbalanced = close - open;
    }
    
    return swap;
}

int main()
{
    
    return 0;
}
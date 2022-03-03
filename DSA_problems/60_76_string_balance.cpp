#include <bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    if(s.size()%2 != 0) return -1;
    int t= 0, ans =0, balance =0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{')
        {
            balance++;
        }
        else
        {
            if(balance == 0)
            {
                ans++;
                balance++; // because we have reversed it so it will be '{'.
                continue;
            }
            balance--;
        } 
    }
    return ans+balance/2;   
}

int main()
{
    
    return 0;
}
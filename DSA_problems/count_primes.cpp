#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) 
{
    vector <bool> v(n+1, true);
    v[0] = false;
    v[1] = false;
    int c=0;
    for (int i = 2; i < n; i++)
    {
        if(v[i])
        {
            c++;
            for (int j = i*2; j <n ; j = j+i)
            {
                v[j] = 0;
            }
        }
    }
    return c;    
}

int main()
{
    
    return 0;
}
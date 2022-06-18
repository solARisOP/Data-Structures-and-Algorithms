#include <bits/stdc++.h>
using namespace std;

char * solve(int n)
{
    int f[100];
    f[0] =1;
    f[1] =1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = i * f[i-1]; 
    }
    string s = to_string(f[n]);
    char *c;
    strcpy(c, s.c_str());
    
    return c;    
}

int main()
{
    int n;
    cin>>n;
    char *c = solve(n);
    cout<<c<<endl;
    
    return 0;
}
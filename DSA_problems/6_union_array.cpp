#include <bits/stdc++.h>
using namespace std;

int unions(int a[], int m, int b[], int n)
{
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        s.insert(b[i]);
    }
    return s.size();
        
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int b[]={31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
    int m = sizeof(a)/sizeof(int);
    int n = sizeof(b)/sizeof(int);
    cout<<unions(a,m,b,n);
    return 0;
}
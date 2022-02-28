#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m)
{
    sort(a1, a1+n);
    for (int i = 0; i < m; i++)
    {
        if(!binary_search(a1, a1+n, a2[i]))
        {
            return "no";
        }    
    }
    return "yes";    
}

int main()
{
    int a1[] = {10, 5, 2, 23, 19};
    int a2[] = {19, 5, 3};
    int n = sizeof(a1)/sizeof(a1[0]);
    int m = sizeof(a2)/sizeof(a2[0]);
    cout<<isSubset(a1,a2,n,m); 
    return 0;
}
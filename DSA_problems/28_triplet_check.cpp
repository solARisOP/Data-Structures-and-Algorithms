#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    set<int> s;
    for (int i = 0; i < n-2; i++)
    {
        int sum = X -A[i];
        for (int j = i+1; j < n; j++)
        {
            if(s.find(sum - A[j])!= s.end())
                return true;
            else
                s.insert(A[i]);    
        }
    }
    return false;  
}    

int main()
{
    
    return 0;
}
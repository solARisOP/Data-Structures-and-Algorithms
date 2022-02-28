#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    int i =0;
    long long j = LONG_LONG_MAX;
    while(i+(m-1) < n-1)
    {
        if(a[i+(m-1)]-a[i]<j)
        {
            j = a[i+(m-1)] - a[i];
        }
        i++;
    }
    return j;
}

int main()
{
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    cout<<findMinDiff(A, 8, 5);
    return 0;
}
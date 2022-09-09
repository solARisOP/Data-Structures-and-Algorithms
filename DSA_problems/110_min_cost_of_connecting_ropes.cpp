#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long,vector<long long>,greater<long long>>p;
    for(long long i = 0; i<n; i++)
    {
        p.push(arr[i]);
    }
    long long sum = 0, result = 0;

    while(p.size()>1)
    {
        long long a = p.top();
        p.pop();
        long long b = p.top();
        p.pop();
        sum = a+b;
        result += sum;
        p.push(sum);
    }
    return result;
}

int main()
{
    long long arr[] = {4, 2, 7, 6, 9};
    long long n = sizeof(arr)/sizeof(long long);
    cout<<minCost(arr, n);
    return 0;
}
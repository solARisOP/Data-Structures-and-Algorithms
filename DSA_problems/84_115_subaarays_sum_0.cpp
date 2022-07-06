#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll findSubarray(vector<ll> arr, int n)
{
    // code here
    int sum = 0, count = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        count += m[sum];
        m[sum]++;
    }
    return count;
}

int main()
{

    return 0;
}
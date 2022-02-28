#include <bits/stdc++.h>
using namespace std;

int find_median(vector<int> v)
{
    if(v.size() == 1) return v[0];
    sort(v.begin(), v.end());
    if(v.size()%2 == 1)
    {
        return v[v.size()/2];
    }
    else
    {
        return ((v[(v.size()/2)-1]+v[v.size()/2])/2);
    }
}

int main()
{
    vector<int> arr= {56, 67, 30, 7};
    cout<<find_median(arr);
    
    return 0;
}
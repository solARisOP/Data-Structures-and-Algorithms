#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    set<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        s.insert(arr[i]);
        auto it = s.upper_bound(arr[i]);

        if (it != s.end())
            arr[i] = *it;
        else
            arr[i] = -1;
    }

    return arr;
}

int main()
{

    return 0;
}
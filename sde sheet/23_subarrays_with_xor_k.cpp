#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int subarraysWithSumK(vector<int> arr, int k)
{
    // Write your code here
    unordered_map<int, int> mpp;

    int n = arr.size();
    int cnt = 0;
    int xori = 0;
    mpp[xori] = -1;

    for (int i = 0; i < n; i++)
    {
        xori ^= arr[i];
        if (mpp.find(xori^k) != mpp.end())
            cnt++;
        mpp[xori] = i;
    }

    return cnt;
}

int main()
{

    return 0;
}
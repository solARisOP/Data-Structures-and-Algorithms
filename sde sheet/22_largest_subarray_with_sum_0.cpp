#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    // Write your code here
    int n = arr.size(), sum = 0, maxi = 0;
    unordered_map<int, int> mpp;
    mpp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mpp.find(sum) != mpp.end()) maxi = max(maxi, i - mpp[sum]);
        else mpp[sum] = i;
    }

    return maxi;
}

int main()
{

    return 0;
}
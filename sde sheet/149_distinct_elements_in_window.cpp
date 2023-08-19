#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    vector<int> ans;
    unordered_map<int, int> mpp;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (i >= k - 1)
        {
            ans.push_back(mpp.size());
            if (!(--mpp[arr[i - k + 1]]))
                mpp.erase(arr[i - k + 1]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> topKFrequent(vector<int> &nums, int k)
{
    priority_queue<pii> pq;
    unordered_map<int, int> mpp;
    for (int it : nums)
        mpp[it]++;
    for (auto it : mpp)
        pq.push({it.second, it.first});

    vi ans;
    while (k--)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{

    return 0;
}
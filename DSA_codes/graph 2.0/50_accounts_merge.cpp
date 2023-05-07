#include <bits/stdc++.h>
#include "46_disjoint_set.h"
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    // code here
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mpp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string mail = accounts[i][j];
            if (mpp.find(mail) == mpp.end())
            {
                mpp[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mpp[mail]);
            }
        }
    }

    vector<string> mergemail[n];
    for (auto it : mpp)
    {
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergemail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (!mergemail[i].size())
            continue;
        sort(mergemail[i].begin(), mergemail[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        temp.insert(temp.begin() + 1, mergemail[i].begin(), mergemail[i].end());
        ans.push_back(temp);
    }

    return ans;
}

int main()
{

    return 0;
}
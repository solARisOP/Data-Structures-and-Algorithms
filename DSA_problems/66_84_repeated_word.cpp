#include <bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
{
    map<string, int> mp;
    for(int i=0; i<n; i++)
    {
        mp[arr[i]]++;
    }
    vector<pair<int, string>> ans;
    map<string, int> :: iterator it;
    for(it = mp.begin() ; it != mp.end() ; it++){
        ans.push_back(make_pair(it->second, it->first));
    }
    sort(ans.begin(), ans.end());
    return ans[ans.size()-2].second;
}

int main()
{
    
    
    return 0;
}
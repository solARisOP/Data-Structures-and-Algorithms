#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

static bool comp(pii a, pii b)
{
    // if(a.second == b.second) return a.first>b.first;
    return a.second<b.second;
}
int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    int n = start.size();
    vp meet;
    for(int i=0; i<n; i++)
    {
        meet.push_back({start[i], end[i]});
    }

    sort(meet.begin(), meet.end(), comp);

    int cnt = 1, limit= meet[0].second;

    for(int i=1; i<n; i++)
    {
        if(limit<meet[i].first)
        {
            limit = meet[i].second;
            cnt++;
        }
        
    }

    return cnt;
}

int main()
{
    
    return 0;
}
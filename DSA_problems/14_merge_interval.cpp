#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>::iterator it;
    it = intervals.begin();
    it++;
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i-1][1]>=intervals[i][0])
        {
            while(intervals[i-1][1]>=intervals[i][0])
            {
                intervals[i-1][1] = intervals[i][1];
                intervals.erase(it);
                it++;
            }
        }
        else
        {
            it++;
        }    
    }
    return intervals;
}

int main()
{
    vector<vector<int>> h = {{1,3},{2,6},{8,10},{15,18}};
    h = merge(h);
    for (int i = 0; i < h.size(); i++)
    {
        for (int j = 0; j < h[i].size(); j++)
        {
            cout<<h[i][j]<<'\t';
        }
        cout<<'\t';
    }
    
    return 0;
}
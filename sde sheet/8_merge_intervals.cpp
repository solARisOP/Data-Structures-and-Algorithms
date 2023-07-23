#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());

    vvi ans;
    ans.push_back(intervals[0]);
    int n = intervals.size();

    for (int i = 1; i < n; i++)
    {
        if (ans.back()[1] >= intervals[i][0])
        {
            if (ans.back()[1] >= intervals[i][1])
                continue;
            else
                ans.back()[1] = intervals[i][1];
        }
        else
            ans.push_back(intervals[i]);
    }

    return ans;
}

int main()
{
    vvi inter = {{1, 4}, {2, 3}};
    vvi ans = merge(inter);
    for (auto it : ans)
        cout << it[0] << " " << it[1] << endl;
    return 0;
}
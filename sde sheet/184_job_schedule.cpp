#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool comp(vi &a, vi &b)
{
    return a[2] > b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comp);
    int m = jobs.size();
    int n = jobs[0].size();
    int max_day = 0;
    for (int i = 0; i < m; i++) max_day = max(max_day, jobs[i][1]);
    vi sched(max_day + 1, -1);
    int profit = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int deadline = jobs[i][1];
        for (int j = deadline; j > 0; j--)
        {
            if (sched[j] == -1)
            {
                sched[j] = jobs[i][0];
                profit += jobs[i][2];
                cnt++;
                break;
            }
        }
    }

    return {cnt, profit};
}

int main()
{
    
    return 0;
}
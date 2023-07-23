#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

static bool comp(vector<int> v1, vector<int> v2)
{
    return v1[1] > v2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comp);
    int n = jobs.size();
    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        max_size = max(max_size, jobs[i][0]);
    }

    vector<int> deadline(max_size + 1, -1);
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int limit = jobs[i][0], money = jobs[i][1];
        if (deadline[limit] == -1)
        {
            deadline[limit] = 0;
            profit += money;
        }
        else
        {
            int j = limit - 1;
            while (j > 0)
            {
                if (deadline[j] == -1)
                {
                    deadline[j] = 0;
                    profit += money;
                    break;
                }
                --j;
            }
        }
    }

    return profit;
}

int main()
{

    return 0;
}
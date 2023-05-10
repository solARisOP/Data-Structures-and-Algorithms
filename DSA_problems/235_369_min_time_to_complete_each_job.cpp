#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    // code here
    vi indegree(n + 1, 0);
    vi adj[n + 1];

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        if (!indegree[i])
            q.push({1, i});
    }

    vi ans(n + 1);
    while (!q.empty())
    {
        int steps = q.front().first;
        int node = q.front().second;

        q.pop();

        ans[node] = steps;

        for (int it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
            {
                q.push({steps + 1, it});
            }
        }
    }

    ans.erase(ans.begin());
    return ans;
}

int main()
{

    return 0;
}
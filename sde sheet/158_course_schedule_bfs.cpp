#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    vi adj[n];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    vi indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (int it : adj[node])
        {
            indegree[it]--;
            if (!indegree[it])
                q.push(it);
        }
    }

    if (cnt == n)
        return true;
    return false;
}

int main()
{

    return 0;
}
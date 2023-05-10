#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// dfs algo
bool dfs_cycle(int node, vi &vis, vi adj[])
{
    vis[node] = 2;

    for (int it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs_cycle(it, vis, adj))
                return true;
        }
        else
        {
            if (vis[it] == 2)
                return true;
        }
    }
    vis[node] = 1;
    return false;
}

bool detectCycleInDirectedGraph_dfs(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vi vis(n + 1, 0);
    vi adj[n + 1];
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (!vis[i])
        {
            if (dfs_cycle(i, vis, adj))
                return true;
        }
    }

    return false;
}

// bfs kahn's algo
bool detectCycleInDirectedGraph_bfs(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vi indegree(n + 1, 0);
    vi adj[n + 1];
    for (auto it : edges)
    {
        int u = it.first;
        int v = it.second;

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i < n + 1; i++)
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
            {
                q.push(it);
            }
        }
    }

    if (cnt == n)
        return false;
    return true;
}
int main()
{

    return 0;
}
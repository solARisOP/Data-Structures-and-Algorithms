#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool dfs(int node, vi &vis, vi adj[])
{
    vis[node] = 2;

    for (int it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, adj))
                return true;
        }
        else if (vis[it] == 2)
            return true;
    }
    vis[node] = 1;
    return false;
}

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    vi adj[n];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    vi vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(i, vis, adj))
            return false;
    }

    return true;
}

int main()
{

    return 0;
}
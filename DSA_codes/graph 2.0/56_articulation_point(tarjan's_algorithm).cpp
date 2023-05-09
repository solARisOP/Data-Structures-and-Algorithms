#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int timer = 1;
void dfs(int node, int parent, vi &vis, vi &tin, vi &low, vi &mark, vi adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, mark, adj);
            low[node] = min(low[it], low[node]);
            if (low[it] >= tin[node] && parent != -1)
                mark[node] = 1;
            child++;
        }
        else
        {
            low[node] = min(tin[it], low[node]);
        }
    }
    if (child > 1 && parent == -1)
        mark[node] = 1;
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    // Code here
    vi tin(V), low(V), vis(V, 0), mark(V, 0), ans;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, -1, vis, tin, low, mark, adj);
    }

    for (int i = 0; i < V; i++)
    {
        if (mark[i])
            ans.push_back(i);
    }

    if (ans.size() == 0)
        return {-1};
    return ans;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

bool dfs(int src, vi &vis, vi &safe, vi adj[])
{
    vis[src] = 2;

    for (int node : adj[src])
    {
        if (!vis[node])
        {
            if(dfs(node, vis, safe, adj))
            {
                return true;
            }
        }
        else if (vis[node] == 2) return true;
    }

    vis[src] = 1;
    safe[src] = 1;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    vi vis(V, 0), safe(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, safe, adj);
        }
    }
    
    vi ans;
    for (int i = 0; i < V; i++)
    {
        if (safe[i] == 1) ans.push_back(i);
    }

    return ans;
}
int main()
{

    return 0;
}
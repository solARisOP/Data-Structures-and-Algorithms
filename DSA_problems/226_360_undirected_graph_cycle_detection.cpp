#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// dfs algo
bool dfs(int node, int parent, vi &vis, vi adj[])
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, vis, adj))
                return true;
        }
        else
        {
            if (it != parent)
                return true;
        }
    }

    return false;
}

string cycleDetection_dfs(vector<vector<int>> &edges, int n, int m)
{
    // Write your code here.
    vi adj[n + 1];
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n + 1, 0);
    for (int i = 0; i < n + 1; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, i, vis, adj))
                return "Yes";
        }
    }

    return "No";
}

// bfs algo
string cycleDetection_bfs(vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vi adj[n+1];
    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi vis(n+1, 0);
    for(int i = 0; i<n+1; i++)
    {
        if(!vis[i])
        {
            queue<pii> q;
            q.push({i, i});
            vis[i] = 1;

            while(q.size())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(int it : adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it] = 1;
                        q.push({it, node});
                    }
                    else if(it != parent) return "Yes";
                }
            }
        }
    }

    return "No";
}

int main()
{

    return 0;
}
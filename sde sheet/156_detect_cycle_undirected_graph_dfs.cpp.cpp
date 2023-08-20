#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool dfs(int node, vi adj[], vi &vis, int parent)
{
    vis[node]++;

    for(int it : adj[node])
    {
        if(!vis[it])
        {
            if(dfs(it, adj, vis, node)) return true;
        }    
        else if(parent != it) return true;
    }

    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vi adj[n+1];
    vi vis(n+1, 0);
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i] && dfs(i, adj, vis, -1)) return "Yes";
    }

    return "No";
}

int main()
{
    
    return 0;
}
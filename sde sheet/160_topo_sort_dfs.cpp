#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vi adj[], vi &vis, vi &ans)
{
    vis[node] = 1;

    for(int it : adj[node])
    {
        if(!vis[it]) dfs(it, adj, vis, ans);
    }

    ans.push_back(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vi adj[v];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    
    vi vis(v, 0), ans;
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    
    return 0;
}
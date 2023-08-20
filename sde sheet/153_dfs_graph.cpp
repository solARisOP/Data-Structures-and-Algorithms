#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int i, vi& vis, vi adj[], vi &ans)
{
    vis[i] = 1;
    ans.push_back(i);
    for(int node : adj[i])
    {
        if(!vis[node])dfs(node, vis, adj, ans);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vi adj[V];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vvi ans;
    vi vis(V,0);

    for(int i=0; i<V; i++)
    {
        vi comp;
        if(!vis[i])
        {
            dfs(i, vis, adj, comp);
            ans.push_back(comp);
        }
    }

    return ans;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

void dfs_graph(int node, vi &vis, vi &ans, vi adj_l[])
{
    vis[node] = 1;
    ans.push_back(node);
    for(auto it : adj_l[node])
    {
        if(!vis[it])
        {
            dfs_graph(it, vis, ans, adj_l);
        }
    }
}


vi dfs(int n, vi adj_l[])
{
    vi vis(n, 0);
    vi ans;
    for(int i =0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs_graph(i, vis, ans, adj_l);
        }
    }

    return ans;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vi &vis, stack<int> &st, vi adj[])
{
    vis[node] = 1;
    
    for(auto it : adj[node])
    {
        if(!vis[it]) dfs(it, vis, st, adj);
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vi adj[v];

    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        
        adj[u].push_back(v);
    }
    
    stack<int> st;
    vi vis(v, 0);
    
    for(int i = 0; i<v; i++)
    {
        if(!vis[i]) dfs(i, vis, st, adj);
    }

    vi ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;    
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;
    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            DFS(i, adj, vis, dfs);
        }
    }
}

vector<int> dfs_of_graph(int n, vector<int> adj[])
{
    vector<int> vis(n+1, 0);
    vector<int> dfs;
    for (int i = 1; i <= n; i++) // this loop is for components
    {
        if(!vis[i])
        {
            DFS(i, adj, vis, dfs);
        }
    }   

    return dfs;
}


void adjacency_list(vector<int> *adj, int n, int e)
{
    for (int i = 0; i < e; i++)
    {
        int u, v; // u and v are nodes 
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
}

int main()
{
    int n, e;
    cin>>n>>e; 

    vector<int> adj_l[n+1]; 
    adjacency_list(adj_l, n, e);
    cout<<endl;
    for (int i = 1; i < n+1; i++)
    {
        for(auto j : adj_l[i])
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto i :dfs_of_graph(n, adj_l)) cout<<i<<"  ";

    return 0;
}
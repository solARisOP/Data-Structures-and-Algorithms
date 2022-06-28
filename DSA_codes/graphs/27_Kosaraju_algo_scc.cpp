#include <bits/stdc++.h>
using namespace std;

void topo_dfs(int node, vector<int> &vis, vector<int> *adj, stack<int> &st) 
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            topo_dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs_scc(int node, vector<int> &vis, vector<int> *transpose)
{
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it : transpose[node])
    {
        if(!vis[it]) dfs_scc(it, vis, transpose);
    }
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
}

int main()
{
    int n = 5;
    vector<int> adj[n+1];

    add_edge(1, 2, adj);
    add_edge(2, 3, adj);
    add_edge(3, 1, adj);
    add_edge(2, 4, adj);
    add_edge(4, 5, adj);

    vector<int> vis(n+1, 0);
    stack<int> st;
    for (int i = 1; i < n+1; i++)
    {
        if(!vis[i])
        {
            topo_dfs(i, vis, adj, st);
        }
    }

    vector<int> transpose[n+1];
    for(int i = 1; i < n+1; i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])
        {
            transpose[it].push_back(i); // if we transpose it we can start traversal from backward
        }
    }
    
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!vis[node])
        {
            cout<<"SCC : ";
            dfs_scc(node, vis, transpose);
            cout<<endl;
        }
    }
    

    return 0;
}
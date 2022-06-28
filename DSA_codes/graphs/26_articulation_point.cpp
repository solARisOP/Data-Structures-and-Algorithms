#include <bits/stdc++.h>
using namespace std;

void dfs_bridge(int node, int parent, int &timer, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], set<int> &art)
{
    vis[node] = 1;
    tin[node] = low[node] = ++timer;
    int child =0;

    for(auto it : adj[node])
    {
        if(it == parent) continue;

        if(!vis[it])
        {
            dfs_bridge(it, node, timer, vis, tin, low, adj, art);
            low[node] = min(low[node] ,low[it]); 
            if(low[it] >= tin[node] && parent != -1) // -1 is if its parent doesnot exist means it cannot go further up so how can it be a articulation point
            {
                art.insert(node);
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]); 
        }
    }

    if(parent == -1 && child > 1)  art.insert(node); // more than 1 child will only exist if more than 1 dfs calls are made for a node's adjacent nodes
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int n = 12;
    vector<int> adj[n+1];
    add_edge(1, 2, adj);
    add_edge(1, 4, adj);
    add_edge(3, 2, adj);
    add_edge(3, 4, adj);
    add_edge(5, 4, adj);
    add_edge(5, 6, adj);
    add_edge(7, 6, adj);
    add_edge(7, 8, adj);
    add_edge(9, 8, adj);
    add_edge(6, 9, adj);
    add_edge(8, 10, adj);
    add_edge(10, 11, adj);
    add_edge(12, 11, adj);
    add_edge(10, 12, adj);

    int timer = 0;
    vector<int> vis(n+1, 0), tin(n+1, -1), low(n+1, -1);
    set<int> art; // because we can get the same node again for diff. adjacent nodes 
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs_bridge(1, -1, timer, vis, tin, low, adj, art);
        }
    }

    for(auto i : art) cout<<i<<"    ";
    
    return 0;
}
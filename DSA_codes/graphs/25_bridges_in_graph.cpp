#include <bits/stdc++.h>
using namespace std;

void dfs_bridge(int node, int parent, int &timer, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = ++timer;

    for(auto it : adj[node])
    {
        if(it == parent) continue; // if it is the we check for other remaining nodes

        if(!vis[it])
        {
            dfs_bridge(it, node, timer, vis, tin, low, adj);
            low[node] = min(low[node] ,low[it]); // after we come back from the dfs call we compare the lowest of both and we store it in our lowest 
            if(low[it] > tin[node]) // if this is true than there exist a bridge
            {
                cout<<it<<" --- "<<node<<endl;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]); // if it is visited and it is not parent means we cant visit it, so we compare and take the lowest
        }
    }
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
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs_bridge(1, -1, timer, vis, tin, low, adj);
        }
    }
    
    return 0;
}
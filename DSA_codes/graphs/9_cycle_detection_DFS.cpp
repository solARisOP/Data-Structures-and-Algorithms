#include <bits/stdc++.h>
using namespace std;

bool cycle_detection_DFS(int node, int pre, vector<int> *adj, vector<int> &vis)
{
    vis[node] = true;

    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            if(cycle_detection_DFS(i, node, adj, vis)) return true;;
        }
        else if(i != pre) return true;
    }

    return false;
}

bool iscycle(int n, vector<int> *adj)
{
    vector<int> vis(n+1, 0);

    for (int i = 1; i < n+1; i++)
    {
        if(!vis[i])
        {
            if(cycle_detection_DFS(i, -1, adj, vis)) return true;
        }
    }
    
    return false;
}


void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[11];

    add_edge(1,2,adj);
    add_edge(3,2,adj);
    add_edge(9,8,adj);
    add_edge(7,8,adj);
    add_edge(5,8,adj);
    add_edge(7,6,adj);
    add_edge(6,4,adj);
    add_edge(6,10,adj);
    add_edge(5,4,adj);

    cout<<iscycle(10, adj);

    return 0;
}
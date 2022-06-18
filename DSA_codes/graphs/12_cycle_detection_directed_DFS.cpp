#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(int node, vector<int> &vis, vector<int> &dfsvis, vector<int> *adj)
{
    vis[node] = 1;
    dfsvis[node] = 1;

    for(auto i : adj[node])
    {
        if(!vis[i])
        {
            if(cycle_detection(i, vis, dfsvis, adj)) return true;
        }
        else if(dfsvis[i]) return true; // if it is visited overall and currently then there is a cycle;
    }

    dfsvis[node] = 0; // when it return backs from the dfs call as there is no going further, we mark it as unvisited as the current is going back
    return false;
}

bool iscycle(int n, vector<int> *adj)
{
    vector<int> vis(n+1, 0); // for overall dfs traversal
    vector<int> dfsvis(n+1, 0);// for current node dfs traversal

    for (int i = 0; i < n+1; i++)
    {
        if(!vis[i])
        {
            if(cycle_detection(i, vis, dfsvis, adj)) return true;
        }
    }
    
    return false;
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
}

int main()
{
    vector<int> adj[10];
    add_edge(1, 2, adj);
    add_edge(2, 3, adj);
    add_edge(3, 4, adj);
    add_edge(3, 6, adj);
    add_edge(4, 5, adj);
    add_edge(6, 5, adj);
    add_edge(7, 2, adj);
    add_edge(7, 8, adj);
    add_edge(8, 9, adj);
    add_edge(9, 7, adj);

    cout<<iscycle(9, adj);
    return 0;
}
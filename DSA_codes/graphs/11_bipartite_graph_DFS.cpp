#include <bits/stdc++.h>
using namespace std;

bool bipartite_check(int node, vector<int> &color, vector<int> *adj)
{
    if(color[node] == -1) color[node] = 1;

    for (auto i : adj[node])
    {
        if(color[i] == -1)
        {
            color[i] = 1 - color[node];
            if(!bipartite_check(i, color, adj)) return false;
        }
        else if(color[i] == color[node]) return false;
    }

    return true;    
}

bool isbipartite(int n, vector<int> *adj)
{
    vector<int> color(n+1, -1);

    for (int i = 1; i < n+1; i++)
    {
        if(color[i] == -1)
        {
            if(!bipartite_check(i, color, adj)) return false;
        }
    }

    return true;    
}

void add_edge(int u, int v, vector<int> *adj)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[12];

    add_edge(1,2,adj);
    add_edge(3,2,adj);
    add_edge(9,8,adj);
    add_edge(7,8,adj);
    // add_edge(5,8,adj);
    add_edge(8,11,adj);
    add_edge(5,11,adj);
    add_edge(7,6,adj);
    add_edge(6,4,adj);
    add_edge(6,10,adj);
    add_edge(5,4,adj);

    cout<<isbipartite(11, adj);

    return 0;
}
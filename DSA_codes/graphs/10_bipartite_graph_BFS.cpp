#include <bits/stdc++.h>
using namespace std;

/*graph with non odd cycle is a bipartite graph means no two adjacent nodes may have the same color*/

bool bipartite_check(int src, vector<int> *adj, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto i : adj[node])
        {
            if(color[i] == -1) // if not colored
            {
                color[i] = 1 - color[node]; // if the adjacent node is 1 this will get 0 and viceversa
                q.push(i);
            }
            else if(color[i] == color[node]) return false; // if these adjacent nodes are of same colors then it's not a bipartite graph
        }
    } 

    return true;
}

bool isbipartite(int n, vector<int> *adj)
{
    vector<int> color(n+1, -1);

    for(int i = 1; i < n+1; i++)
    {
        if(color[i] == -1)
        {
            if(!bipartite_check(i, adj, color)) return false;
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
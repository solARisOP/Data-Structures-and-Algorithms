#include <bits/stdc++.h>
using namespace std;

void find_topo(int node, stack<int> &st, vector<pair<int,int>> *adj, vector<int> &vis)
{
    vis[node] = 1;

    for(auto i : adj[node])
    {
        if(!vis[i.first])
        {
            find_topo(i.first, st, adj, vis);
        }
    }

    st.push(node);
}

vector<int> shortest_path(int src, int n, vector<pair<int,int>> *adj)
{
    vector<int> vis(n, 0), dist(n, INT_MAX);
    stack<int> st;
    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            find_topo(i, st, adj, vis);
        }
    }

    // after finding the topological sort we take one by one element from the stack and find its minimum distance from the source

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(dist[node] != INT_MAX)
        {
            for(auto i : adj[node])
            {
                if(dist[node]+i.second < dist[i.first])
                {
                    dist[i.first] = dist[node] + i.second;
                }
            }
        }
    }
    
    return dist;
}

void add_edge(int u, pair<int, int> p, vector<pair<int,int>> *adj)
{
    adj[u].push_back(p);
}

int main()
{
    // directed acyclic graph with weights
    vector<pair<int, int>> adj[6];
    
    add_edge(0, {1,2}, adj);
    add_edge(0, {4,1}, adj);
    add_edge(1, {2,3}, adj);
    add_edge(2, {3,6}, adj);
    add_edge(4, {2,2}, adj);
    add_edge(4, {5,4}, adj);
    add_edge(5, {3,1}, adj);

    for(auto i : shortest_path(0, 6, adj)) cout<<i<<"   ";
    return 0;
}
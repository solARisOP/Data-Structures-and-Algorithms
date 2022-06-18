#include <bits/stdc++.h>
using namespace std;

void findtopo(int node, stack<int> &st, vector<int> &vis, vector<int> *adj)
{
    vis[node] = 1;

    for(auto i : adj[node])
    {
        if(!vis[i]) findtopo(i, st, vis, adj);
    }
    
    st.push(node);
}

vector<int> toposort(int n, vector<int> *adj)
{
    stack<int> st;
    vector<int> vis(n+1, 0);

    for (int i = 0; i < n+1; i++)
    {
        if(!vis[i])
        {
            findtopo(i, st, vis, adj);
        }
    }
    

    vector<int> topo;
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
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

    for(auto i :toposort(9, adj)) cout<<i<<"    ";
 
    return 0;
}
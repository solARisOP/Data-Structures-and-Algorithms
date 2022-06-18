#include <bits/stdc++.h>
using namespace std;

// storing of an undirected graph in adjacency list (less space complexity than matrix representation)
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
    cin>>n>>e; // n is number of nodes and m is number of edges

    vector<int> adj_l[n+1]; // 1 based graph node indexing
    adjacency_list(adj_l, n, e);

    //printing adjacency list
    for (int i = 1; i < n+1; i++)
    {
        cout<<i<<" : ";
        for(auto j : adj_l[i])
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
    
    int adj_m[n+1][n+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            adj_m[i][j] = 0;
        }
    }

    // adjacency matrix representation
    for (int i = 0; i < e; i++)
    {
        int u, v; // u and v are nodes 
        cin>>u>>v;

        adj_m[u][v] = 1;
        adj_m[v][u] = 1;
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout<< adj_m[i][j]<<"   ";
        }
        cout<<endl;
    }
    

    return 0;
}
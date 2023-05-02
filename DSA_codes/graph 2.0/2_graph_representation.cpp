#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

int main()
{
    int n, m;
    cin>>n>>m; // n = no. of nodes, m = no. of edges
    vii adj_m(n+1, vi(n+1, 0)); // adjacency matrix for 1 based indexing
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_m[u][v] = 1;
        adj_m[v][u] = 1;
    }

    vi adj_l[n+1]; // adjacency list for 1 based indexing
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_l[u].push_back(v);
        adj_l[v].push_back(u);
    }

    return 0;
}
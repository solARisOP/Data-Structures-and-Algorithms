#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }    
};



bool comp(node a, node b)
{
    return a.wt < b.wt;
}

void makeset(int n, vector<int> &parent)
{
    for (int i = 1; i < n; i++)
    {
        parent[i] = i;
    }
}

int find_par(int n, vector<int> &parent)
{
    if(n == parent[n]) return n;

    return parent[n] = find_par(parent[n], parent);
}

void union_make(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = find_par(u, parent);
    v = find_par(v, parent);

    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[v] < rank[u]) parent[v] = u;
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int main()
{
    int n, m;
    cin>> n >>m ;

    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;

        edges.push_back(node(u, v, wt)); // for the nodes and their weights
    }

    sort(edges.begin(), edges.end(), comp); // sorted the edges based on their weights

    vector<int> parent(n+1), rank(n+1, 0);

    makeset(n+1, parent); // initially everyone is thier own parent in the mst(meaning before the start of the mst)

    int cost = 0; // for the cost of the resultant mst;

    vector<pair<int, int>> mst;

    for(auto it: edges)
    {
        if(find_par(it.u, parent) != find_par(it.v, parent)) // if they do not have the same parent in the mst
        {
            mst.push_back({it.u, it.v}); // we take them into mst
            cost+=it.wt; // we add the cost
            union_make(it.u, it.v, parent, rank); // we attach them into one;
        }
    }
    cout<<endl;
    cout<<"cost : "<<cost<<endl;

    for(auto it : mst) cout<<it.first<<" -- "<<it.second<<endl;
    
    return 0;
}
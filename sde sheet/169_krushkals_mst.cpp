#include <bits/stdc++.h>
using namespace std;
#include "DSA_codes\graph 2.0\46_disjoint_set.h"

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.
    DisjointSet ds(n+1);
    vector<pair<int,pair<int,int>>> tr_edges;

    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        tr_edges.push_back({wt,{u,v}});        
    }
    
    sort(tr_edges.begin(), tr_edges.end());

    int mst=0;
    for(auto it : tr_edges)
    {
        int u = it.second.first;
        int v = it.second.second;
        
        int wt = it.first;
        int ulp_u = ds.findUPar(u);
        int ulp_v = ds.findUPar(v);
        if(ulp_u != ulp_v)
        {
            ds.unionBySize(u,v);
            mst+=wt;
        }         
    }

    return mst;
}


int main()
{
    
    return 0;
}
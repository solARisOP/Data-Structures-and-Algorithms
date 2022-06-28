#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int u, v, wt;
        node(int first, int last, int weight)
        {
            u = first;
            v = last;
            wt = weight;
        }
};

int main()
{
    int n = 6, m = 7;
    vector<node> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;

        edges.push_back(node(u, v, wt)); 
    }

    int src = 0;
    vector<int> dist(n,INT_MAX);

    dist[src] = 0;

    for (int i = 1; i <= n-1; i++) // we exactly have to run this loop till number of nodes -1 
    {
        for(auto it : edges)
        {
            if((dist[it.u] + it.wt) < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 0;

    // and extra one time, but this time just only to check becuase if this time the inner if statement satisfies then it means there is a negative cycle
    for(auto it : edges)
    {
        if((dist[it.u] + it.wt) < dist[it.v])
        {
            cout<<"contains a negative cycle"<<endl;
            flag = 1;
            break;
        }
    }

    // and if that statement dont statisfies then the last dist array is the shortest path from src to all nodes
    if(!flag)
    {
        for(auto it : dist)
        {
            cout<<it<<" ";
        }
    }
    
    return 0;
}
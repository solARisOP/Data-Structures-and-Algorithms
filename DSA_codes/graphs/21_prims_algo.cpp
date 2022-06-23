#include <bits/stdc++.h>
using namespace std;

// brute force with time complexity ≈ n^2
void min_spanning_tree(int n, vector<pair<int, int>> *adj)
{
    vector<int> key(n,INT_MAX), mst(n, 0), parent(n, -1);
    key[0] = 0;

    for(int i = 0; i<n-1; i++)
    {
        int mini = INT_MAX, node;

        for(int j= 0; j<n; j++)
        {
            if(mst[j] == false && key[j] < mini)
            {
                mini = key[j]; 
                node = j; // we take the node which is not yet included in mst and is the minimum in all of key values
            }
        }
        mst[node] = true; // we include it in the mst;

        for(auto it : adj[node])
        {
            int ad_node = it.first; // we take its adjacent nodes
            int wt = it.second; // and also their corresponding edge weights
            if(mst[ad_node] == false && key[ad_node]> wt) // we check if that node is not yet included in the mst and its wt is lesser than the key weight and if it is so
            {
                parent[ad_node] = node; // we assign the corresponding 'node' as its parent
                key[ad_node] = wt; // and update its key weight
            }
        }

        // and the following process goes on until we had done it for all minimal edges
    }

    for (int i = 1; i < n; i++)
    {
        cout<<parent[i]<<" ---- "<<i<<endl; // the spanning tree 
    }

}

// efficient approach with time complexity ≈ nlogn
void min_spanning_tree_eff(int n, vector<pair<int, int>> *adj)
{
    vector<int> key(n,INT_MAX), mst(n, 0), parent(n, -1);
    key[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; // min. heap gives us the minimum element in 'log n' while in the brute forec we were costing ourselves 'n'
    // and pq contains only that elements which are not in the mst;
    pq.push({0,0}); // we are pushing 0 and its key 0 in the pq(first parameter is key wt and second one is the node)

    while(!pq.empty())
    {
        int node = pq.top(). second; // here we are getting the element with min. key weightt to its parent node
        pq.pop();

        mst[node] = true; // including it in the mst

        for(auto it : adj[node])
        {
            int ad_node = it.first; 
            int wt = it.second; 
            if(mst[ad_node] == false && wt < key[ad_node]) // if it fulfills the corresponding condition 
            {
                parent[ad_node] = node; // then we update its parent
                key[ad_node] = wt; // update its key weightt to its parent
                pq.push({key[ad_node], ad_node}); // and push it in the min. heap
            }
        }

        // we repeat the following process till the heap is empty or we can do it for all the 'n-1' edges        
    }

    for (int i = 1; i < n; i++)
    {
        cout<<parent[i]<<" ---- "<<i<<endl; // the spanning tree
    }
    
}

void add_edge(int u, int v, int wt, vector<pair<int, int>> *adj)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}

int main()
{
    vector<pair<int, int>> adj[5];
    add_edge(0, 1, 2, adj);
    add_edge(0, 3, 6, adj);
    add_edge(3, 1, 8, adj);
    add_edge(1, 2, 3, adj);
    add_edge(4, 1, 5, adj);
    add_edge(4, 2, 7, adj);

    min_spanning_tree_eff(5, adj);

    return 0;
}
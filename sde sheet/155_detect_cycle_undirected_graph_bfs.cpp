#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vi adj[n+1];
    vi vis(n+1, 0);
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            queue<pii> q;
            q.push({i, -1});
            vis[i]++;
            
            while(!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for(int it : adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it]++;
                        q.push({it, node});
                    }
                    else if(it != parent) return "Yes"; 
                }
            }
        }
    }

    return "No";
}


int main()
{
    
    return 0;
}
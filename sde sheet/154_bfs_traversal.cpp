#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    vi ans;
    vi vis(n, 0);

    for(int i = 0; i< n; i++)
    {
        if(!vis[i])
        {
            queue<int> q;
            vis[i] = 1;
            q.push(i);

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(int it : adj[node])
                {
                    if(!vis[it])
                    {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }

    return ans;
}

int main()
{
    
    return 0;
}
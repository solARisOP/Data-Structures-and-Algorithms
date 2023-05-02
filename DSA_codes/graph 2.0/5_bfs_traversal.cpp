#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

vi bfs(int n, vi adj_l[])
{
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
                for(int it : adj_l[node])
                {
                    if(!vis[node])
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
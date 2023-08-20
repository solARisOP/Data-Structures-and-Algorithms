#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vi & vis, vi adj[], stack<int> & st)
{
    vis[node] = 1;

    for(int it : adj[node])
    {
        if(!vis[it])dfs(it, vis, adj, st);
    }

    st.push(node);
}
void k_dfs(int node, vi & vis, vi adj[], vi& ans)
{
    vis[node] = 1;
    ans.push_back(node);

    for(int it : adj[node])
    {
        if(!vis[it])k_dfs(it, vis, adj, ans);
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vi adj[n];
    vi adj_r[n];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj_r[it[1]].push_back(it[0]);
    }
    stack<int> st;
    vi vis(n,0);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])dfs(i, vis, adj, st);
    }
    vi visi(n,0);
    vvi ans;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(visi[node]) continue;
        vi scc;
        k_dfs(node, visi, adj_r, scc);
        ans.push_back(scc);
    } 
    return ans;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void dfs(int node, vi &vis, stack<char> &st, vi adj[])
{
    vis[node] = 1;
    for (int it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, st, adj);
    }

    st.push(char(node + 'a'));
}

vector<char> getAlienLanguage(string dictionary[], int n)
{
    // Write your code here.
    unordered_set<char> st;

    for (int i = 0; i < n; i++)
    {
        for (auto it : dictionary[i])
        {
            st.insert(it);
        }
    }

    int V = st.size();

    vi adj[V];
    for (int i = 0; i < n - 1; i++)
    {
        int size = min(dictionary[i].length(), dictionary[i + 1].length());

        int j = 0;

        string a = dictionary[i];
        string b = dictionary[i + 1];

        while (j < size)
        {
            if (a[j] != b[j])
            {
                int u = a[j] - 'a';
                int v = b[j] - 'a';

                adj[u].push_back(v);
                break;
            }
            j++;
        }
    }

    stack<char> s;
    vi vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, vis, s, adj);
    }

    vector<char> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{

    return 0;
}
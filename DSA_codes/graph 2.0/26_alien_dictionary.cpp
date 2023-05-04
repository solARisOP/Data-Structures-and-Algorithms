#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define vp vector<pair<int, int>>

string findOrder(string dict[], int N, int v)
{
    // code here
    vi adj[v];

    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int len = min(s1.size(), s2.size());
        for (int x = 0; x < len; x++)
        {
            if (s1[x] != s2[x])
            {
                adj[s1[x] - 'a'].push_back(s2[x] - 'a');
                break;
            }
        }
    }

    vi indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (int it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (!indegree[i])
            q.push(i);
    }

    string ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(char(node + 'a'));

        for (int i : adj[node])
        {
            indegree[i]--;
            if (!indegree[i])
                q.push(i);
        }
    }

    return ans;
}

int main()
{

    return 0;
}
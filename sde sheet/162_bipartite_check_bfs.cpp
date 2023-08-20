#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vi colour(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (colour[i] == -1)
        {
            queue<int> q;
            q.push(i);

            colour[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                int col = colour[node];
                for (int it : graph[node])
                {
                    if (colour[it] == -1)
                    {
                        colour[it] = 1 - col;
                        q.push(it);
                    }
                    else if (colour[it] == col)
                        return false;
                }
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}
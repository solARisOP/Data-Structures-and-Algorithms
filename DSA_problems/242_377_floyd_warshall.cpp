#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.
    vii mat(n + 1, vi(n + 1, 1e9));
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        mat[u][v] = wt;
    }
    for (int i = 1; i <= n; i++)
    {
        mat[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mat[i][k] != 1e9 && mat[k][j] != 1e9)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    return mat[src][dest];
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// doesnot run for bigger test cases but it can tell the number of steps
int minSteps(int m, int n, int d)
{
    // Code here
    queue<pair<int, pii>> q;
    vii dist(m+1, vi(n+1, 1e9));
    q.push({0, {0, 0}});

    dist[0][0] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int jugm = it.second.first;
        int jugn = it.second.second;

        int steps = it.first;

        // cout<<jugm<<" "<<jugn<<"  "<<steps<<endl;

        if (jugm == d || jugn == d) return steps;

        if (jugm == 0)
        {
            if (dist[m][jugn] > steps + 1)
            {
                dist[m][jugn] = steps + 1;
                q.push({steps + 1, {m, jugn}});
            }
        }

        if (jugn == 0)
        {
            if (dist[jugm][n] > steps + 1)
            {
                dist[jugm][n] = steps + 1;
                q.push({steps + 1, {jugm, n}});
            }
        }

        if (jugm > 0)
        {
            if (dist[0][jugn] > steps + 1)
            {
                dist[0][jugn] = steps + 1;
                q.push({steps + 1, {0, jugn}});
            }
        }

        if (jugn > 0)
        {
            if (dist[jugm][0] > steps + 1)
            {
                dist[jugm][0] = steps + 1;
                q.push({steps + 1, {jugm, 0}});
            }
        }

        if (jugm > 0)
        {
            int a, b;
            if(jugn + jugm <= n)
            {
                b = jugn + jugm;
                a = 0;
            }
            else
            {
                int transfer = n - jugn;
                b = n;
                a = jugm - (transfer);
            }
            if(dist[a][b] > steps + 1)
            {
                dist[a][b] = steps + 1;
                q.push({steps + 1, {a, b}});
            }
        }

        if (jugn > 0)
        {
            int a, b;
            if(jugm + jugn <= m)
            {
                a = jugm + jugn;
                b = 0;
            }
            else
            {
                int transfer = m - jugm;
                a = m;
                b = jugn - (transfer);
            }

            if(dist[a][b] > steps + 1)
            {
                dist[a][b] = steps + 1;
                q.push({steps + 1, {a, b}});
            }
        }
    }

    return -1;
}

// this will work for large testcases but it can only tell if the solution
// if the solution is possible or not, it doesnot return the number of steps
int minSteps_(int m, int n, int d)
{
    int ult = n + m; //(total capacity)

    queue<int> q;
    vi vis(ult + 1, 0);

    q.push(0);
    vis[0] = 1;

    int delta[] = {-m, -n, n, m};
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        if(node == d) return true;
        for(int i = 0; i<4; i++)
        {
            int newnode  = node + delta[i];
            if(newnode <= ult && newnode>=0 && !vis[newnode])
            {
                vis[newnode] = 1;
                q.push(newnode);
            } 
        }
    }

    return false;
}

int main()
{
    cout<<minSteps_(3, 5, 4);
    return 0;
}
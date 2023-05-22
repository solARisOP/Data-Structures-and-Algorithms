#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;

    public:
        vector<int> size;
        DisjointSet(int n)
        {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i = 0; i<=n; i++)
            {
                parent[i] = i;
            }
        }

        int findUPar(int n)
        {
            if(parent[n] == n)
            {
                return n;
            }

            return parent[n] = findUPar(parent[n]);
        }

        void unionByRank(int u, int v)
        {
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if(up_u == up_v) return;

            if(rank[up_u] < rank[up_v])
            {
                parent[up_u] = up_v;
            }
            else if(rank[up_v] < rank[up_u])
            {
                parent[up_v] = up_u;
            }
            else
            {
                parent[up_v] = up_u;
                rank[up_v]++;
            }
        }

        void unionBySize(int u, int v)
        {
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if(up_u == up_v) return;

            if(rank[up_u] < rank[up_v])
            {
                parent[up_u] = up_v;
                size[up_v]+=size[up_u];
            }
            else
            {
                parent[up_v] = up_u;
                size[up_u]+=size[up_v];
            }
        }
};

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    DisjointSet ds(n);
    
    for(auto it : astronaut)
    {
        int u = it[0];
        int v = it[1];
        
        ds.unionBySize(u,v);
    }
    
    vi combis;
    long long sum = 0;
    for(int i = 0;i<n; i++)
    {
        if(ds.findUPar(i) == i)
        {
            combis.push_back(ds.size[i]);
            sum+=ds.size[i];
        }
    }
    
    long long ans = 0;
    for(int i =0; i<combis.size(); i++)
    {
        sum = sum - combis[i];
        ans = ans + (combis[i]*sum);
    }
     
    return ans;
}

int main()
{
    int n, p;
    cin>>n>>p;

    vii astronauts(p, vi(2));
    for(int i = 0; i<p; i++)
    {
        int u, v;
        cin>>u>>v;
        astronauts[i][0] = u;
        astronauts[i][1] = v;

    }

    cout<<journeyToMoon(n, astronauts);

    return 0;
}
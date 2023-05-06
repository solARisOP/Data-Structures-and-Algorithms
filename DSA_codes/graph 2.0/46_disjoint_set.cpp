#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class DisjointSet
{
    private:
        vi rank, parent, size;

    public:
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

            return parent[n] = findUPar(n-1);
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


int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same"<<endl;
    else cout<<"Notsame"<<endl;

    ds.unionBySize(3,7);

    if(ds.findUPar(3) == ds.findUPar(7)) cout<<"same"<<endl;
    else cout<<"Notsame"<<endl;

    return 0;
}
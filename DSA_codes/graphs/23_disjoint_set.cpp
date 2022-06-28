#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int rnk[100000];

void makeset(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        rnk[i]  = 0;
    }
}

int find_par(int n)
{
    if(n == parent[n]) return n;

    return parent[n] = find_par(parent[n]);
}

void union_make(int u, int v)
{
    u = find_par(u);
    v = find_par(v);

    if(rnk[u] < rnk[v]) parent[u] = v;
    else if(rnk[v] < rnk[u]) parent[v] = u;
    else
    {
        parent[u] = v;
        rnk[v]++;
    }
}

int main()
{
    makeset(11);

    int m;
    cin>>m;
    while(m--)
    {
        int u, v;
        cin>>u>>v;

        union_make(u,v);
    }

    // if they belong to the same component
    if(find_par(2) == find_par(3)) cout<<"same component"<<endl;
    else cout<<"different component"<<endl;

    return 0;
}
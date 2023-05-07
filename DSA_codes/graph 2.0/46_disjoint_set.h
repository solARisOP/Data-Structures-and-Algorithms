class DisjointSet
{
    vector<int> rank, parent, size;

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

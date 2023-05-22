#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vi shortest_dist(int N, vi adj[])
{
	vi dist(N+1, 1e9);
	dist[1] =0;
	queue<pii> q;

	q.push({0, 1});

	while(!q.empty())
	{
		int node = q.front().second;
		int dis = q.front().first;

		q.pop();
		for(int v : adj[node])
		{
			if(dist[v] > dis + 1)
			{
				dist[v] = dis + 1;
				q.push({dist[v], v});
			}
		}

	}

	return dist;
}

vector<string> hide_n_seek(int N, vi adj[], int Q, vii &queries)
{
	vector<string> ans;
	vi level = shortest_dist(N, adj);
	for(auto it : queries)
	{
		int king = it[0];
		int dest = it[1];
		int src = it[2];

		vi vis(N+1, 0);
		vis[src] = 1;

		queue<int> q;
		q.push(src);

		int flag = 0;
        int fl =1;
		while(!q.empty())
		{
			int node = q.front();
			q.pop();

			if(node == dest)
			{
				flag = 1;
				break; 
			}
            if(node == 1 && !fl) continue;
            fl =0; 
			for(int v : adj[node])
			{
				if(!vis[v])
				{
					if((!king && level[v]<level[src]) || (king && level[v]>level[src]))
					{
						vis[v] =1;
						q.push(v);
					}
				}
			}
		}
		if(flag) ans.push_back("YES");
		else ans.push_back("NO");
	}

    return ans;	
}

int main() {
	int N;
	cin>>N;
	vi adj[N+1];

	for(int i = 0; i<N-1; i++)
	{
		int A,B;
		cin>>A>>B;

		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	int Q;
	cin>>Q;

	vii queries;
	for(int i = 0; i<Q; i++)
	{
		int x, end, start;
		cin>>x>>end>>start;

		vi temp = {x, end, start};
		queries.push_back(temp);
	}

	vector<string> ans = hide_n_seek(N, adj, Q, queries);

	for(string it : ans) cout<<it<<endl;

    return 0;
}
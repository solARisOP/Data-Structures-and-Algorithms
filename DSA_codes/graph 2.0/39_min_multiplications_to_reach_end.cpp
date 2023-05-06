#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        queue<pii> q;
        vi dist(1e5, 1e9);
        q.push({0, start});
        dist[start] = 0;
        int mod = 1e5;
        while(!q.empty())
        {
            int node = q.front().second;
            int steps = q.front().first;
            
            q.pop();
            for(int i=0; i<n; i++)
            {
                int v = (node * arr[i])%mod;
                if(steps + 1 < dist[v])
                {
                    dist[v] = steps + 1;
                    if(end == v) return steps+1;
                    q.push({dist[v], v});
                }
            }
        }
        
        return -1;
    }

int main()
{
    
    return 0;
}
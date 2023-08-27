#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int maxProfit(vector<int> &vals, vector<int> &wgts, int n, int w)
{
	// Write your code here
	vi prev(w+1, 0), curr(w+1, 0);
    
	for(int i=0; i<=w; i++)
	{
		if(i>=wgts[0]) prev[i] = vals[0];
	}

	for(int i=1; i<n; i++)
	{
		for(int wt = 0; wt<=w; wt++)
		{
			int n_pick = 0 + prev[wt];
			int pick = 0;
			if(wt>=wgts[i]) pick = vals[i] + prev[wt-wgts[i]];

			curr[wt] = max(pick, n_pick);
		}
		prev = curr;
	}
	return curr[w];
}

int main()
{
    
    return 0;
}
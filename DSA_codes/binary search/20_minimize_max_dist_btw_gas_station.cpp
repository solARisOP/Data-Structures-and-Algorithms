#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// brute force
long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	vi how_many(n-1, 0);

	for(int j =0; j< k; j++)
	{
		long double maxi = -1;
		int idx = -1;
		for(int i = 0; i<n-1; i++)
		{
			long double diff = arr[i+1] - arr[i];
			long double sec_len = diff/(long double)(how_many[i]+1);

			if(maxi < sec_len)
			{
				maxi = sec_len;
				idx = i;
			}
		}
		how_many[idx]++;
	}

	long double ans = -1.0;

	for(int i =0; i<n-1; i++)
	{
		long double diff = arr[i+1] - arr[i];
		long double sec_len = diff/(long double)(how_many[i]+1);
		ans = max<long double>(ans, sec_len);
	}	

	return ans;
}

// better approach
long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	vi how_many(n-1, 0);
	priority_queue<pair<long double, int>> pq;

	for(int i = 0; i<n-1; i++)
	{
		long double diff = arr[i+1] - arr[i];
		pq.push({diff, i});
    }

    for(int j =0; j< k; j++)
	{
		long double dist = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		how_many[idx]++;
		dist = (long double)(arr[idx+1] - arr[idx])/(long double)(how_many[idx]+1);
		pq.push({dist, idx});
	}

	return pq.top().first;
}

// most optimal O(1) - space complexity
bool solve(vi &arr, int k, long double diff)
{
	int cnt = 0;
	int n = arr.size();
	for(int i=0; i<n-1; i++)
	{
		int gas_sts = (arr[i+1] - arr[i])/diff;
		if((long double)gas_sts*diff == (long double)(arr[i+1] - arr[i])) gas_sts--;

		cnt+=gas_sts;
		if(cnt > k) return 0;
	}
	
	return 1;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for(int i =0; i<n-1; i++)
	{
		high = max<long double>(high, (long double)(arr[i+1] - arr[i])); 
	}
	
	long double diff = 1e-6;

	while((high - low) > diff)
	{
		long double mid = low + (high - low)/2.0;

		bool x = solve(arr, k, mid);

		if(x)high = mid;
		else low = mid;
	}

	return high;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int k){
	// Write your code here.
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	priority_queue<pair<int, pii>> pq;
	pq.push({A[n-1] + B[n-1], {n-1, n-1}});

	set<pii> myset;
	myset.insert({n-1, n-1});
	vi ans;

	while(k)
	{
		auto it = pq.top(); 
		pq.pop();

		int sum = it.first;
		int x = it.second.first;
		int y = it.second.second;

		ans.push_back(sum);
		if(myset.find({x, y-1}) == myset.end())
		{
			myset.insert({x, y-1});
			pq.push({A[x]+B[y-1], {x, y-1}});
		}
		if(myset.find({x-1, y}) == myset.end())
		{
			myset.insert({x-1, y});
			pq.push({A[x-1]+B[y], {x-1, y}});
		}
		--k;
	}

	return ans;
}
int main()
{
    
    return 0;
}
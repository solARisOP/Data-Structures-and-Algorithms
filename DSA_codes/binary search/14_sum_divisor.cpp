#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vector<int>& arr, int limit, int div)
{
	double sum = 0;
	int n = arr.size();
	for(int i=0; i<n; i++)
	{
		sum += ceil((double)arr[i]/(double)div);
		if(sum > limit) return 0;
	}

	return 1;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int low = 1;
	int high = *max_element(arr.begin(), arr.end());

	while(low <= high)
	{
		long long mid = low + (high - low)/2;
		bool x = solve(arr, limit, mid);

		if(x) high = mid - 1;
		else low = mid + 1;
	}

	return low;
}

int main()
{
    
    return 0;
}
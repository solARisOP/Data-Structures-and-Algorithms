#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    vector<int> dp(n);
	for(int i=0; i<n; i++) dp[i] = arr[i];
    int maxi =0;
    for (int i = 0; i < n ; i++)
    {
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(arr[prev]<arr[i])
            {
                dp[i] = max(dp[i], dp[prev]+arr[i]); // max till the lis generated now
            }
        }
		maxi = max(dp[i], maxi);
    }

    return maxi;
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	return longestIncreasingSubsequence(rack, n);
}

int main()
{
    
    return 0;
}
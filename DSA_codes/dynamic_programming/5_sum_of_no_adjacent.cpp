#include <bits/stdc++.h>
using namespace std;

// memoization

int solve(int ind, vector <int>& dp, vector <int>& nums)
{
	if(ind == 0) return nums[ind];
	if(ind < 0) return 0;
	if(dp[ind] != -1) return dp[ind];

	int pick = nums[ind] + solve(ind -2, dp, nums); // here we are adding sum of the two non adjacent elements
	int npick = 0 + solve(ind -1, dp, nums); // here we are not adding the current element and therefore taking the process to next element
	
	int ans = max(pick, npick); // picking up the maximum as it was asked the question
	dp[ind] = ans;
	return ans;
}

int maximumNonAdjacentSum_mem(vector<int> &nums)
{
	int n = nums.size();
	vector <int> dp(n, -1);
	return solve(n-1, dp, nums);
}

// tabulation
int maximumNonAdjacentSum_tab(vector<int> &nums)
{
	int n = nums.size();
	vector <int> dp(n);
	dp[0] = nums[0] ;
	for(int i = 1; i<n; i++)
	{
		int p = nums[i];
		if(i>1) p += dp[i-2];
		int np = 0 + dp[i-1];
        // the above two steps are as of the same as mentioned in the memoization 
		dp[i] = max(p, np);
	}
	return dp[n-1];
}

// tablution with O(1) space complexity
int maximumNonAdjacentSum_tab1(vector<int> &nums)
{
	int n = nums.size();
	int prev = nums[0];
	int prev2 = 0;
	for(int i = 1; i<n; i++)
	{
		int p = nums[i];
		if(i>1) p+=prev2;
		int np = prev;

		int curr = max(p, np);
		prev2 = prev;
		prev = curr;
	}
	return prev;
}
long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

int main()
{

    return 0;
}
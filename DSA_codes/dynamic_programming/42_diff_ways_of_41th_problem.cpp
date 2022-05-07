#include <bits/stdc++.h>
using namespace std;

// tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // no need to write the base cases as all are declared 0 initially and the base case is itself 0
    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = i-1; j >= -1; j--) // j = i -1 because we are getting the previous index
        {
            int n_take = 0 + dp[i+1][j+1]; // because we are storing the value next to what is the present index thatswhy we have to write j+1
            int take = 0;
            if(j == -1 || arr[i]>arr[j]) take = 1 + dp[i+1][i+1]; // same as the reason above

            dp[i][j+1] = max(n_take, take);
        }
    }
    
    return dp[0][-1 +1];
}

// tabulation with space optimization
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> after(n+1, 0), curr(n+1, 0);
    for (int i = n-1; i >= 0 ; i--)
    {
        for (int j = i-1; j >= -1; j--) 
        {
            int n_take = 0 + after[j+1]; 
            int take = 0;
            if(j == -1 || arr[i]>arr[j]) take = 1 + after[i+1]; 

            curr[j+1] = max(n_take, take);
        }
        after = curr;
    }
    
    return after[-1 +1];
}

// tabulation with 1-d space optimization and different algorithm
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    int maxi =1;
    for (int i = 0; i < n ; i++)
    {
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(arr[prev]<arr[i])
            {
                dp[i] = max(dp[i], dp[prev]+1); // max till the lis generated now
            }
        }
		maxi = max(dp[i], maxi);
    }

    return maxi;
} 

// printing the longest increasing subsequence 
// below used process is from a backtracking analysis of the LIS 1-d array optimization
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1), hash(n); // hash array stores the indexs of the elements
    int maxi =0, last_ind = 1;
    for (int i = 0; i < n ; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(arr[prev]<arr[i] && dp[prev]+1 > dp[i])
            {
                dp[i] = dp[prev]+1;
                hash[i] = prev; // we are updating the index for backtracking it further 
            }
        }
		if(dp[i]> maxi)
        {
            maxi = dp[i];
            last_ind = i; // we are storing the index of the end element of longest increasing subsequence till index i
        }
    }
    
    vector<int>temp;
    temp.push_back(arr[last_ind]); // we have stored the last element of the LIS
    while(hash[last_ind] != last_ind) // until the last_ind is the value of the hash[last_ind] itself this will backtrack
    {
        last_ind = hash[last_ind]; // we are using the backtracking here to update the last_ind here
        temp.push_back(arr[last_ind]); // as we updated the last_ind we are pushing that element
    }

    reverse(temp.begin(), temp.end()); // reversing the the array as we have stored from largest to smallest index

    for (auto i : temp)
    {
        cout<<i<<" ";
    }
    
    return maxi;
}

int main()
{
    
    return 0;
}
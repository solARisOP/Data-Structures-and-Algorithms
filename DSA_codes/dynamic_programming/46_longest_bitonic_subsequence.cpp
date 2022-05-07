#include <bits/stdc++.h>
using namespace std;

// it is asked bitonic so it can be increasing than decreasing or only increasing or only decreasing
int longestBitonicSequence(vector<int>& arr, int n) 
{
	vector<int> dp1(n, 1), dp2(n, 1);
    int maxi =0;;

    // so first compute for increasing
    for (int i = 0; i < n ; i++)
    {
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(arr[i]>arr[prev])
            {
                dp1[i] = max(dp1[i], dp1[prev]+1);
            }
        }
    }

    // then compute for decreasing
    for (int i = n-1; i >= 0 ; i--)
    {
        for (int prev = n-1; prev > i; prev--) 
        {
            if(arr[i]>arr[prev])
            {
                dp2[i] = max(dp2[i], dp2[prev]+1);
            }
        }
        maxi = max(maxi, dp1[i]+dp2[i]-1); // then checking which is the maximum
    }
    
    return maxi;
} 


int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int>& nums){
    int n = nums.size();
	long long prev = nums[0];
	long long prev2 = 0;
	for(int i = 1; i<n; i++)
	{
		long long p = nums[i];
		if(i>1) p+=prev2;
		long long np = prev;

		long long curr = max(p, np);
		prev2 = prev;
		prev = curr;
	}
	return prev;
}
// same as sum of no adjacent numbers but with a slight change
long long int houseRobber(vector<int>& valueInHouse)
{
	vector<int> arr1;
    vector<int> arr2;
    int n = valueInHouse.size();
	if(n==1) return valueInHouse[0];
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(valueInHouse[i]);
        if(i!=n-1) arr2.push_back(valueInHouse[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}

int main()
{
    string s;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool checkit(string &a, string &b)
{
    int al = a.length();
    int bl = b.length();
    if(al - bl != 1) return 0;

    int i, j, k;
    i = j = k = 0;
    while(i < al)
    {
        if(a[i] == b[j]) i++, j++;
        else
        {
            if(k == 1) return 0; // as soon as its the second element that doesnot match then we return 0;
            i++;
            k++;
        }
    }
    return 1;
}

bool comp(string &a, string &b)
{
	return a.size()<b.size();
}

int longestStrChain(vector<string> &arr) // sol. taken from dp-42 different algoritm with slight change
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi =1;
	sort(arr.begin(), arr.end(), comp); // coz they asked us sequence not subsequence so order doesn't matter and it will be easy for us and we sort it according to size that's why used a comparater
    for (int i = 0; i < n ; i++)
    {
        for (int prev = 0; prev <= i-1; prev++) 
        {
            if(checkit(arr[i],arr[prev]))
            {
                dp[i] = max(dp[i], dp[prev]+1);
            }
        }
		maxi = max(dp[i], maxi);
    }

    return maxi;
}

int main()
{
    vector<string> s = {"m", "nm", "mmm"};
    cout<<longestStrChain(s);
    return 0;
}
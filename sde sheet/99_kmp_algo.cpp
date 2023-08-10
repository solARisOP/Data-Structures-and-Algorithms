#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n = pattern.length();
	vector<int> pi(n, 0), ans;
	int i=0, j=1;
	while(j<n)
	{
		if(pattern[i] == pattern[j])
        {
            pi[j] = i+1;
            i++, j++;
        }
		else
		{

			if(i>0) i=pi[i-1];
			else j++;
		}

	}

	i=0, j=0;
	int m = text.length();
	while(i<m)
	{
		if(text[i] == pattern[j])
		{
			i++, j++;
			if(j == n)
			{
				ans.push_back(i-n+1);
				j=pi[j-1];
			}
		} 
		else
		{
			if(j>0) j=pi[j-1];
			else i++;
		}
	}

	return ans;
}



int main()
{
    stringMatch("ababacabab", "aba");
    return 0;
}
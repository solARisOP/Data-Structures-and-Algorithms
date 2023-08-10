#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int minCharsforPalindrome(string str) {
	// Write your code here.
	string pattern = str+'#';
	reverse(str.begin(), str.end());
	pattern +=str;
	int n = pattern.length();
	vector<int> pi(n, 0);
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

	return str.length() - pi[n-1];
}

int main()
{
    
    return 0;
}
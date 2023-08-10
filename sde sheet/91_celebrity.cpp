#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool knows (int a, int b){return 1 || 0;} // this is knownly a dummy implementation

int findCelebrity(int n) {
 	// Write your code here.
	int celeb = 0, last = 0;
	for(int i=1; i<n; i++)
	{
		if(knows(celeb, i) || !knows(i, celeb))
		{
			last = i;
			celeb = i;
		}
	}

	for(int i=0; i<last; i++)
	{
		if(i == celeb) continue;
		if(!knows(i, celeb) || knows(celeb, i)) return -1;
	}

	return celeb;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

void solve(stack<int> &st, int x)
{
	if(st.empty() || x > st.top())
	{
		st.push(x);
		return;
	}
	int curr = st.top();
	st.pop();
	solve(st, x);
	st.push(curr);
	
}
void sortStack(stack<int> &st)
{
	// Write your code here
	
	if(st.empty()) return;

	int x = st.top();
	st.pop();
	sortStack(st);
	solve(st, x);
}

int main()
{
    
    return 0;
}
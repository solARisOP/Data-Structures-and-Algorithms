#include <bits/stdc++.h>
using namespace std;

# define ll long long

// T.C ≈ O(N), S.C ≈ k
vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K) 
{
    deque<ll> dq;
    vector<ll> ans;
   
    for(ll i =0; i<N; i++)
    {
        if(!dq.empty() && dq.front() == i-K) dq.pop_front();
        if(arr[i]<0) dq.push_back(i);

        if(i>=K-1)
        {
            if(!dq.empty())ans.push_back(arr[dq.front()]);
            else ans.push_back(0);
        }
    }
   
    return ans;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vector<int> &v, int h, int val)
{
    int hr = 0;
    int n = v.size();
    for(int i = 0; i<n; i++)
    {
        int time_taken = v[i]/val;

        if(!time_taken || v[i]%val) hr++;
        hr+=time_taken;
        if(hr>h) return 0;
    }

    return 1;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
    int maxi = *max_element(v.begin(), v.end());
    int low = 1, high = maxi;
    
    while(low <= high)
    {
        long long mid = low + (high - low)/2;
        bool x = solve(v, h, mid);
        
        if(x) high = mid -1;
        else low = mid + 1;
    }

    return low;
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

bool solve(vector<int> &weights, int d, int wt)
{
    int sum = 0;
    int n = weights.size();
    int days = 1;
    for(int i=0; i<n; i++)
    {
        sum+=(weights[i]);
        if(sum > wt)
        {
            days++;
            sum = weights[i];
        }
        if(days > d) return 0;
    }

    return days <= d;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int low = *max_element(weights.begin(), weights.end());

    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low <= high)
    {
        long long mid = low + (high - low)/2;

        bool x = solve(weights, d, mid);

        if(x) high = mid -1;
        else low = mid + 1;
    }

    return low;
}

int main()
{
    
    return 0;
}
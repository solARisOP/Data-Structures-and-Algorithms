#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

int solve(vector<int> &arr, int students, int max_pgs)
{
    int n = arr.size();
    int sum=0;
    int stds = 1;
    for(int i =0; i<n; i++)
    {
        sum+=arr[i];
        if(sum > max_pgs)
        {
            stds++;
            sum = arr[i];
        }
    }
    if(stds <= students) return 1;
    return 0;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        long long mid = low + (high - low)/2;

        int x = solve(arr, m, mid);
        if(x) high = mid - 1;
        else low = mid + 1;
    }

    return low; 
}

int main()
{
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

// using lower and upper bound
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    if(lb == n || arr[lb] != k) return {-1, -1};
    int ub = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
    return {lb, ub-1};
}

// using plain binary search
int first_occurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n-1;
    int first = -1;

    while(low<=high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k)
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return first;
}

int last_occurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n-1;
    int last = -1;

    while(low<=high)
    {
        int mid = low + (high - low)/2;

        if(arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k)
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return last;
}

pair<int, int> firstAndLastPosition_(vector<int>& arr, int n, int k)
{
    // Write your code here
    int fo = first_occurence(arr, n, k);
    if(fo == -1) return {-1, -1};
    return {fo, last_occurence(arr, n, k)};
}

//count occurences
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int fo = first_occurence(arr, n, x);
    if(fo == -1) return 0;
    return last_occurence(arr, n, x) - fo + 1;
}

int main()
{
    
    return 0;
}
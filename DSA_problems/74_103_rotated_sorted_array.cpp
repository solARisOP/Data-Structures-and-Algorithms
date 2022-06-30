#include <bits/stdc++.h>
using namespace std;

int binary(vector<int> arr, int element, int size, int l)
{
    int low=l, high = size-1, mid;
    while(low<=high)
    {
        mid = low + (high - low)/2;
        if(element==arr[mid])
        {
            return mid;
        }
        else if(element>arr[mid])
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return -1;
}

int search(vector<int>& nums, int x) 
{
    int n = nums.size();
    int t;

    for(int i =n-2; i>=0; i--)
    {
        if(nums[i]<nums[i+1]) continue;
        else
        {
            t = i;
            break;
        } 
    }
    if(x > nums[n-1]) return binary(nums, x, t+1, 0);
    else return binary(nums, x, n, t+1);
}    

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int x = 0;
    cout<<search(nums, x);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool binarysearch(vector<int> arr, int s, int e, int key)
{
    sort(arr.begin(), arr.end());
    if(s>e)
    {
        return false;
    }
    int m = s+(e-s)/2;
    if(arr[m] == key)
    {
        if(m==arr.size()-1 && arr[m-1] == arr[m]) return true;
        else if(m<arr.size()-1 && (arr[m+1] == arr[m] || arr[m-1] == arr[m]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(key<arr[m])
    {
        return binarysearch(arr, s, m-1, key);
    }
    else 
    {
        return binarysearch(arr, m+1, e, key);
    }
}

int  findDuplicate(vector<int>& nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        if(s.find(nums[i]) == s.end())
        {
            s.insert(nums[i]);
        }
        else
        {
            return nums[i]; 
        }
    }
    return -1;    
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout<<findDuplicate(nums);
    
    return 0;
}
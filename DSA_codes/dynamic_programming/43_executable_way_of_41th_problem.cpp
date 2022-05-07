#include <bits/stdc++.h>
using namespace std;

// binary search method we are replicating the LIS so whatever the length of the array is coming at last we return 
// note : this will not work for printing the LIS, because the temp array is not the LIS, we are just vusing the temp array's length to return the answer
// this came from an binary search lowerbound method 
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
	temp.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
            len++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i]; // instead of storing it in an new array we are replicating the array, thatswhy we can't use it to print the LIS
        }    
    }

    return len; 
}

int main()
{
    
    return 0;
}
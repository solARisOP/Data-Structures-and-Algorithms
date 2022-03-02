#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(int N, vector<int> arr)
{
    int indexg = -1;
    int indexl = -1;
    for (int i = N-2; i >= 0; i--)
    {
        if(arr[i]< arr[i+1])
        {
            indexl = i;
            break;
        }
    }

    if(indexl == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for (int i = N-1; i >= 0; i--)
    {
        if(arr[i]> arr[indexl])
        {
            indexg = i;
            break;
        }
    }
    
    swap(arr[indexl], arr[indexg]);
    reverse(arr.begin()+indexl+1, arr.end());
    return arr;    
}

int main()
{
    vector<int> arr = {1, 3, 4, 5, 2};
    arr = nextPermutation(arr.size(), arr);
    for(auto i: arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 3; i++)
    {
        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            int tar = arr[i] + arr[j];
            int low = j + 1, high = arr.size() - 1;
            while (low < high)
            {
                if (tar + arr[low] + arr[high] == k)
                {
                    ans.push_back({arr[i], arr[j], arr[low], arr[high]});
                    int l = arr[low];
                    int h = arr[high];
                    low++;
                    high--;
                    while (low < high && arr[low] == l)
                        low++;
                    while (low < high && arr[high] == h)
                        high--;
                }

                else if (tar + arr[low] + arr[high] < k)
                    low++;
                else
                    high--;
            }
            while (j + 1 < arr.size() and arr[j] == arr[j + 1])
                j++;
        }
        while (i + 1 < arr.size() and arr[i] == arr[i + 1])
            i++;
    }
    return ans;
}

int main()
{

    return 0;
}
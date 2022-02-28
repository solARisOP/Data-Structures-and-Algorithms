#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void subsets(int in[], vector<int> out, int i, vector<vector<int>>& x)
{
    if(i >= 6)
    {
        if(out.size() < 1)
        {
            // cout<<"blank set"<<endl;
            return ;
        }
        print(out);
        x.push_back(out);
        return;
    }

    // exclude case
    subsets(in, out, i+1, x);

    // include case
    int element = in[i];
    out.push_back(element);
    subsets(in, out, i+1, x);
    return;
}

int solve(int in[], vector<int> out, int i, vector<vector<int>>& x)
{
    int p = 0, sum;
    subsets(in, out, 0, x);
    cout<<endl;
    for (int j = 0; j < x.size(); j++)
    {
        sum = 0;
        for (int k = 0; k < x[j].size(); k++)
        {
           sum = sum + x[j][k];
        }
        if(sum % in[0] == 0)
        {
            p++;
        }
    }
    return p;  
}

int main()
{
    int arr1[6]= {2, 3, 4,5,98,54};
    vector<int> arr2;
    vector<vector<int>>x;
    cout<<solve(arr1, arr2, 0, x)<<endl;
    return 0;
}
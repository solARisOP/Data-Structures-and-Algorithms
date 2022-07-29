#include <bits/stdc++.h>
using namespace std;

int main()
{
    // given an array of numbers, every number appear twice except two numbers, find the numbers

    int arr[] = { 2, 2, 4, 5, 3, 7 , 1, 4, 1, 3};
    int xo = 0;
    for(int i : arr) xo = xo ^i;

    int ind = 0;
    while(xo)
    {
        if(xo&1) break; // for current index if it is true we break, else we do ind ++;

        ind++;
        xo = xo>>1;
    }

    int n1=0, n2 =0;
    for(auto i : arr)
    {
        if(i & (1<<ind)) n1 = n1 ^i;
        else n2 = n2 ^ i;
    }

    cout<<n1<<" "<<n2;

    // given an array of numbers, print xor of all subsets
    int arr2[] = {8,9,6};
    // it will always be 0 cause every number will appear even number of times in all the subsets combined


    // given array , generate all the subsets
    int arr3[] = {2, 3, 4};
    int n = 3;

    // power set algorithm T.C = 2^n *n
    for(int num = 0; num<= (1<<n)-1; num++) // 1<<n means 2 power n
    {
        vector<int> ans;
        for(int bit = 0; bit<n; bit++)
        {
            if(num&(1<<bit)) ans.push_back(arr3[bit]);
        }
        for(int it : ans) cout<<it<<"   ";
        cout<<endl;
    }

    // peter and a combination lock
    // power set algo

    int arr4[] = {10, 20, 30, 40};
    int n = sizeof(arr4)/sizeof(arr4[0]);

    int flag = 0;
    for(int i = 0; i<=(1<<n)-1; i++) 
    {
        int sum =0;
        for (int bit = 0; bit < n; bit++)
        {
            if(i & (1<<bit)) sum += arr4[bit];
            else sum -= arr4[bit];
        }
        if(sum % 360 == 0)
        {
            flag = 1;
            break;
        }     
    }

    flag ? cout<<"YES" : cout<<"NO";
    return 0;
}
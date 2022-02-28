#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    if(N == 1) return 1;
    sort(arr, arr+N);
    int i=0,p=1, t=0;
    while(i<N-1)
    {
        if(arr[i] == arr[i+1])
        {
            i++;
            continue;
        }
        if(arr[i]+1 == arr[i+1])
        {
            p++;
        }
        else
        {
            if(t<p)
            {
                t=p;    
            }
            p=1;            
        }
        i++;
    }
    if(t<p)
    {
        t=p;
    }
    return t;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7};
    cout<<findLongestConseqSubseq(a, sizeof(a)/sizeof(int));
    return 0;
}
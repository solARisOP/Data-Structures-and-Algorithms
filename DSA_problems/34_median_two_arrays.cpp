#include <bits/stdc++.h>
using namespace std;

int getMedian(int ar1[], int ar2[], int n, int m)
{
    int j =0;
    int i = n;
    for(i,j; j<m; i++,j++)
    {
        ar1[i] = ar2[j];
    }
    sort(ar1, ar1+(n+m));
    if((n+m)%2 == 1)
    {
        return ar1[(n+m)/2];
    }
    else
    {
        return (ar1[(n+m)/2-1]+ar1[(n+m)/2])/2;
    }
}
 

int main()
{
    int ar1[] = {900}; 
    int ar2[] = {5,8,10,20,20}; 
    int n1 = sizeof(ar1)/sizeof(ar1[0]); 
    int n2 = sizeof(ar2)/sizeof(ar2[0]); 
    cout << getMedian(ar1, ar2, n1, n2);
    return 0;
}
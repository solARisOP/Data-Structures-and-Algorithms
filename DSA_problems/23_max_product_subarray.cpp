#include <bits/stdc++.h>
using namespace std;

long long maxi(long long a, long long b)
{
    return (a > b) ? a : b;
}

long long mini(long long a, long long b)
{
    return (a < b) ? a : b;
}

long long maxProduct(vector<int> arr, int n) 
{
    if(n==1) return arr[0];
    long long t = 1;
    long long mi = 1, ma = 1;
	for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0) 
        {
            ma = 1;
            mi = 1;
        }    
        else if(arr[i]<0)
        { 
            long long  z = mi;
            mi = arr[i]*ma;           
            ma = max<long long>(arr[i]*z, 1);//because we want to use before value of mi not present updated value.
            if(t<ma) t= ma;
        }
        else
        {
            ma*=arr[i];
            mi = min<long long>(arr[i]*mi, 1);
            if(t<ma) t= ma;  
        }
    }
    return t;
}

int main()
{
    vector<int> a = {8, -2, -2, -2, -1};
    cout<<maxProduct(a, a.size());
    return 0;
}
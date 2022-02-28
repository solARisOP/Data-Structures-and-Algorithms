#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int> > arr, int n, int m)
{
	int c, ans = INT_MAX, r = -1;
    for (int i = 0; i < n; i++)
    {
        c=m;
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] ==1)
            {
                c=j;
                break;
            }
        }
        if( c ==m ) continue;
        if(c<ans)
        {
            ans = c;
            r =i;
        }
        
    }
    return r;
}

// better approach

// int rowWithMax1s(vector<vector<int> > arr, int n, int m)
// {
//     int r = -1, i =0; j = m-1;

//     while(i<n && j>=0)
//     {
//         if(arr[i][j] == 1)
//         {
//             r =i;
//             j--;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return r;
// }


int main()
{
    
    return 0;
}
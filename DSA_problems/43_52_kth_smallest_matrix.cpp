#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int mat[][3], int n, int k)
{
    priority_queue<int> q;
    int i=0,j;
    for (i ; i < n; i++)
    {
        j=0;
        for (j; j < n; j++)
        {
            if(q.size()==k) break;
            q.push(mat[i][j]);
        }
        if(q.size()==k) break;        
    }
    for (i ; i < n; i++)
    {
        for (j ; j < n; j++)
        {
            if(mat[i][j]< q.top())
            {
                q.pop();
                q.push(mat[i][j]);
            }
        }
        j=0;        
    }
    
    return q.top();
}
// better approach

// int kthSmallest(int arr[MAX][MAX], int n, int k){
//    //Your code here
//    priority_queue<int> pq;
   
//    for(int i=0;i<k;i++){
       
//        pq.push(arr[i/n][i%n]); // here i/n and i%n will traverse all the rows and columns upto k.
//    }
//    for(int i=k;i<n*n;i++){
       
//        if(pq.top()>arr[i/n][i%n]){
           
//            pq.pop();
//            pq.push(arr[i/n][i%n]);
//        }
//    }
   
//    return pq.top();
// }

int main()
{
    int mat[3][3] =  {9, 12, 20, 25, 2, 3, 4, 5, 6};
    cout<<kthSmallest(mat, 3, 7);
    
    return 0;
}
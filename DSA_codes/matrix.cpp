#include <bits/stdc++.h>
using namespace std;

void printmatrix(int **arr, int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            cout<<arr[r][c]<<'\t';
        }
        cout<<endl;
    }
}

void row_sum (int arr[][4], int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        int s =0;
        for (int c = 0; c < col; c++)
        {
            s+=arr[r][c];
        }
        cout<<s<<endl;
    }
}
bool ispresent(int arr[][4], int row, int col, int target)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            if(arr[r][c] == target) return true;
        }
    }
    return false;
}

int main()
{
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12}; // this take row wise input.
    // int arr[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int arr[3][4];

    // row wise input.
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            cin>>arr[r][c];
        }
    }

    // column wise input.
    // for (int c = 0; c < 4; c++)
    // {
    //     for (int r = 0; r < 3; r++)
    //     {
    //         cin>>arr[r][c];
    //     }
    // }
    // if(ispresent(arr, 3, 4, 5)) cout<<"found";
    // else cout<<"not found";
    row_sum(arr, 3, 4);
    
    return 0;
}
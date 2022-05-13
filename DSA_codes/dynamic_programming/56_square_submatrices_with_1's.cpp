#include <bits/stdc++.h>
using namespace std;

int countSquares(int n, int m, vector<vector<int>> &arr) 
{
    vector<vector<int>> dp(n, vector<int>(m));

    // below we are copying elements from 1st row and column, this will help us to cal. the whole matrix square because we consider the right bottom of a square to form the whole square  
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0];
    }

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = arr[0][j];
    }

    // below process came from an analysis of the right bottom of every square, if it is orginally 0 then it dont form any square but if it is 1 then it can form 1 size, 2 size... etc sizes squares if possible 
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
			if(arr[i][j] == 0) dp[i][j] = 0; // if it s 0 then we cannot form a square from it
			else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1; // but if it is 1 then we consider it as the right bottom part of a square and we take the min. of the diagonal, left and right element that we computed on the dp table and add a 1 to it, this came from an analysis by considering every element as an right bottom part of a square 
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += dp[i][j]; // we sum up the dp table elements because every value contains the number of square we can make by considering it as an right bottom part in the arr
        }
    }
    
    return ans;
}


int main()
{
    
    return 0;
}
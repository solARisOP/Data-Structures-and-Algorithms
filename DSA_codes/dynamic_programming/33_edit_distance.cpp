#include <bits/stdc++.h>
using namespace std;

// memoization
int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if(i<0) return j+1; // if the given string gets exhausted means and resulatant still have some elements left, it means we have to insert the remaing elements to the given string, so wherever the resultant string index is standing that + 1 will be the no. of elements inserted.
    if(j<0) return i+1; // if the resultant string is exhausted and there still is some elements left in the given string so we have to delete that elements, so wherever the given string index is standing that + 1 will be the no. of elements deleted.

    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i] == str2[j]) return dp[i][j] = 0 + solve(i-1, j-1, str1, str2, dp); // if they both match we go forward, we do not need to do any other operations
    else
    {
        // if characters doesn't match
        int ins = 1 + solve(i, j-1, str1, str2, dp); // we insert an matching element hypothetically right after the current element in the given string, so it will match and we move in the resultant string. We don't move in the given string because we matched a element after the current element so does the current element index have to move.
        int del = 1 + solve(i-1, j, str1, str2, dp); // we delete in the given string hypothetically so we have to move further in the given string and the resulatant string element doesn't match so we stay.
        int rep = 1 + solve(i-1, j-1, str1, str2, dp); // we replace with a matching element hypothetically with the current element in the given string, so both the strings will match and we move forward in both the strings

        return dp[i][j] = min(ins, min(del, rep));
    }

}

int editDistance(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();
    vector<vector<int>> dp(s1, vector<int>(s2, -1));
    return solve(s1-1, s2-1, str1, str2, dp);
}

// memoization by right shifting the indexes by one(1 based indexing).
int solve(int i, int j, string &str1, string &str2, vector<vector<int>> &dp)
{
    if(i==0) return j; // because of right shifting we donot have to do plus 1
    if(j==0) return i; // because of right shifting we donot have to do plus 1
	
	if(dp[i][j] != -1) return dp[i][j];
	
    if(str1[i-1] == str2[j-1]) return dp[i][j] = solve(i-1, j-1, str1, str2, dp);
    else
    {
        int ins = 1 + solve(i, j-1, str1, str2, dp); 
		int del = 1 + solve(i-1, j, str1, str2, dp); 
		int rep = 1 + solve(i-1, j-1, str1, str2, dp); 

        return dp[i][j] = min(ins, min(del, rep));
    }
}

int editDistance(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();
    vector<vector<int>> dp(s1+1, vector<int>(s2+1, -1));
    return solve(s1, s2, str1, str2, dp);
}

// tabulation
int editDistance(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();
    vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= s2; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else
            {
                int ins = 1 + dp[i][j-1]; 
	        	int del = 1 + dp[i-1][j]; 
	        	int rep = 1 + dp[i-1][j-1]; 

                dp[i][j] = min(ins, min(del, rep));
            }
        }
    }

    return dp[s1][s2];
}

// tabulation with space optimization
int editDistance(string str1, string str2)
{
    int s1 = str1.size(), s2 = str2.size();
    vector<int> prev(s2+1, 0), curr(s2+1, 0);
    for (int j = 0; j <= s2; j++) prev[j] = j; // according to first base case;

    for (int i = 1; i <= s1; i++)
    {
        curr[0]  = i; // according to the 2nd base case;
        for (int j = 1; j <= s2; j++)
        {
            if(str1[i-1] == str2[j-1]) curr[j] = prev[j-1];
            else
            {
                int ins = 1 + curr[j-1]; 
	        	int del = 1 + prev[j]; 
	        	int rep = 1 + prev[j-1]; 

                curr[j] = min(ins, min(del, rep));
            }
        }
        prev = curr;
    }

    return prev[s2];
}

int main()
{
    
    return 0;
}
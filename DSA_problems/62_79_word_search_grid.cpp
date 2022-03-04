#include <bits/stdc++.h>
using namespace std;

bool existlinear(vector<vector<char>>grid, string word, int r, int c, int si)
{
    if(si >= word.length())
    {
        return true;
    }
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!= word[si])
    {
        return false;
    }


    char temp = grid[r][c];
    grid[r][c]=' ';
    bool found =  existlinear(grid, word, r+1, c-1, si+1)|| existlinear(grid, word, r-1, c-1, si+1) || existlinear(grid, word, r-1, c+1, si+1) ||existlinear(grid, word, r+1, c+1, si+1) ;

    grid[r][c] = temp;

    return found;
   

}
bool existdiagonal(vector<vector<char>>grid, string word, int r, int c, int si)
{
    if(si >= word.length())
    {
        return true;
    }
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!= word[si])
    {
        return false;
    }


    char temp = grid[r][c];
    grid[r][c]=' ';
    bool found =existdiagonal(grid, word, r+1, c-1, si+1) || existdiagonal(grid, word, r-1, c-1, si+1) || existdiagonal(grid, word, r-1, c+1, si+1) ||existdiagonal(grid, word, r+1, c+1, si+1) ;

    grid[r][c] = temp;

    return found;
   

}

vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
{
    vector<vector<int>> ans;
    char q =word[0];
    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            if(q == grid[r][c] && (existlinear(grid, word, r, c, 0) || existdiagonal(grid, word, r, c, 0)))
            {
                cout<<"inside"<<" "<<r <<" "<<c<<endl;;
                ans.push_back({r,c});
            }
        }
    }
    return ans;
    
}

int main()
{
    vector<vector<char>> grid = {{'a','b','a','e','b','e','e','e','c','c'},
                                 {'a','b','e','c','b','d','e','c','a','d'},
                                 {'e','c','c','c','c','a','d','a','c','b'},
                                 {'e','e','a','d','d','d','c','b','b','b'},
                                 {'b','d','b','a','c','a','b','b','d','d'},
                                 {'c','c','c','d','a','e','a','c','e','b'}};

    string s = "bed"; 
    // cout<<"inmain"<<endl;
    vector<vector<int>> ans = searchWord(grid, s);
    // cout<<"inmain2"<<endl;

    for(auto i : ans)
    {
        for(auto it : i)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
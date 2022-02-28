#include <bits/stdc++.h>
using namespace std;

void print(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<"    ";
    }
    cout<<endl;
}

bool issafe(vector<vector<int>>& visited, vector<vector<int>>& o, int x, int y, int n)
{
    // cout<<"came"<<endl;
    if((x>=0 && x<n) && (y<n && y>=0))
    {
        if((visited[x][y] == 0) && (o[x][y] == 1))
        {
            // cout<<"returning"<<endl;
            return true;
        }
        else
        {
            return false;
        }    
    }
    else
    {
        // cout<<"else"<<endl;
        return false;
    }
    
}

void solve(vector<vector<int>>& o, vector<vector<int>>& visited, int x, int y, string r, vector<string>& a, int n)
{
    if(x == n-1 && y == n-1)
    {
        a.push_back(r);
        return;
    }

    visited[x][y] = 1;

    //down
    int newx = x+1;
    int newy = y;
    if(issafe(visited, o, newx, newy, n))
    {
        // cout<<"D";
        r.push_back('D');
        solve(o, visited, newx, newy, r, a, n);
        r.pop_back();
    }

    //up
    newx = x-1;
    newy = y;
    if(issafe(visited, o, newx, newy, n))
    {
        // cout<<"U";
        r.push_back('U');
        solve(o, visited, newx, newy, r, a, n);
        r.pop_back();
    }

    //right
    newx = x;
    newy = y+1;
    if(issafe(visited, o, newx, newy, n))
    {
        // cout<<"R";
        r.push_back('R');
        solve(o, visited, newx, newy, r, a, n);
        r.pop_back();
    }

    //left
    newx = x;
    newy = y-1;
    if(issafe(visited, o, newx, newy, n))
    {
        // cout<<"L";
        r.push_back('L');
        solve(o, visited, newx, newy, r, a, n);
        r.pop_back();
    }
    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>>o ={ {1, 0, 0, 1},
                            {1, 1, 0, 1},
                            {1, 1, 0, 0},
                            {0, 1, 1 ,1} };
    vector<vector<int>>visited = o;                        
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            visited[i][j] =0;
        }
    }

    int srcx =0;
    int srcy =0;
    vector<string>a;
    string r;
    solve(o, visited, srcx, srcy, r, a, 4);
    sort(a.begin(), a.end());
    print(a);
                  
    return 0;
}
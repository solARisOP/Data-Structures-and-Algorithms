#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
    public:
        int val;
        Node *left;
        Node *right;

        Node() : val(0), left(NULL), right(NULL) {}
        Node(int x) : val(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : val(x), left(a), right(b) {}
};

int max_width(Node * root)
{
    int ans = 0;
    if(!root) return ans;
    queue<pair<Node *, int>> q; // node and its index  
    q.push({root, 0});
    while(!q.empty())
    {
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for(int i = 0; i< size; i++)
        {
            int curr =  q.front().second - min; // to avoid the over flow of the indexing we substract the min index of the level and then derive them for their children
            if(i == 0) first = curr;
            if(i == size -1) last = curr;

            Node * temp = q.front().first;
            q.pop();
            if(temp->left) q.push({temp->left, 2*curr +1});
            if(temp->right) q.push({temp->right, 2*curr +2});
        }
        ans = max(ans, last - first +1); // tracking the max width
    }

    return ans;
}

int main()
{
    
    return 0;
}
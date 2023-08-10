#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

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

vector<int> bottomView(Node * root){
    // Write your code here.
    vi ans;
    if(!root) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            Node *temp = q.front().first;
            int lvl = q.front().second;
            q.pop();

            mpp[lvl] = temp->val;
            if(temp->left) q.push({temp->left, lvl-1});
            if(temp->right) q.push({temp->right, lvl+1});
        }
    }

    for(auto it : mpp) ans.push_back(it.second);

    return ans;
}

int main()
{
    
    return 0;
}
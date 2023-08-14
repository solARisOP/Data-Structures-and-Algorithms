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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string ans="";
        if(!root) return ans;

        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                Node* temp = q.front();
                q.pop();
                if(!temp)
                {
                    ans+="#,";
                    continue;
                } 
                else ans+=to_string(temp->val)+",";
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        ans.pop_back();
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.empty()) return NULL;
        int n = data.size();
        int i=0;
        vector<Node*> nums;
        while(i<n)
        {
            string s="";
            while(i<n && data[i]!=',') s.push_back(data[i++]);
            if(s=="#") nums.push_back(NULL);
            else nums.push_back(new Node(stoi(s)));
            i++;
        }
        n= nums.size();
        i =0;
        int j=i+1;
        while(j<n)
        {
            if(!nums[i])
            {
                i++;
                continue;
            }
            Node* root = nums[i++];
            root->left = nums[j++];
            if(j<n) root->right = nums[j++];
        }

        return nums[0];
    }
};

int main()
{
    
    return 0;
}
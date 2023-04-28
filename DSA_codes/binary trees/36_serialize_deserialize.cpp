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

string serialize(Node *root)
{
    if (!root)
        return "";
    string s = "";
    queue<Node *> q;
    s.append(to_string(root->val) + ',');
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.front();
        q.pop();

        if (!temp->left)
            s.append("#,");
        else
        {
            s.append(to_string(temp->left->val) + ',');
            q.push(temp->left);
        }

        if (!temp->right)
            s.append("#,");
        else
        {
            s.append(to_string(temp->right->val) + ',');
            q.push(temp->right);
        }
    }

    return s;
}

Node *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    queue<Node *> q;
    stringstream s(data); // we can iterate through string like blocks
    string str;
    getline(s, str, ','); // it gives u the string before the ','
    Node *root = new Node(stoi(str));
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        getline(s, str, ','); 
        if (str == "#")
            temp->left = NULL;
        else
        {
            temp->left = new Node(stoi(str));
            q.push(temp->left);
        }

        getline(s, str, ',');
        if (str == "#")
            temp->right = NULL;
        else
        {
            temp->right = new Node(stoi(str));
            q.push(temp->right);
        }
    }

    return root;
}

int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>

class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node() : data(0), left(NULL), right(NULL) {}
        Node(int x) : data(x), left(NULL), right(NULL) {}
        Node(int x, Node *a, Node *b) : data(x), left(a), right(b) {}
};

int KthSmallestElement(Node *root, int k)
{
    // add code here.
    Node *temp = root;
    int ans = -1, count = 0;

    while (temp)
    {
        if (!temp->left)
        {
            if (k == ++count)
            {
                ans = temp->data;
                break;
            }
            temp = temp->right;
        }
        else
        {
            Node *prev = temp->left;
            while (prev->right && prev->right != temp)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = temp;
                temp = temp->left;
            }
            else
            {
                prev->right = NULL;
                if (k == ++count)
                {
                    ans = temp->data;
                    break;
                }
                temp = temp->right;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}
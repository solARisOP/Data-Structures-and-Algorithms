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

int kthLargest(Node *root, int k)
{
    // Your code here
    Node *temp = root;
    int ans = 0, count = 0;

    while (temp)
    {
        if (!temp->right)
        {
            if (k == ++count)
            {
                ans = temp->data;
                break;
            }
            temp = temp->left;
        }
        else
        {
            Node *prev = temp->right;

            while (prev->left && prev->left != temp)
                prev = prev->left;

            if (!prev->left)
            {
                prev->left = temp;
                temp = temp->right;
            }
            else
            {
                prev->left = NULL;
                if (k == ++count)
                {
                    ans = temp->data;
                    break;
                }
                temp = temp->left;
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}
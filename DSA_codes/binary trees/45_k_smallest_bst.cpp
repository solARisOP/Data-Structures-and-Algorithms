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

int kthSmallest(Node *root, int k)
{
    Node *curr = root;
    int count = 0, ans = 0;

    while (curr)
    {
        if (!curr->left)
        {
            count++;
            if (k == count)
                ans = curr->data;
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
                prev = prev->right;

            if (!prev->right)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                if (k == count)
                    ans = curr->data;
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main()
{

    return 0;
}
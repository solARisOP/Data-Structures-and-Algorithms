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

class BSTiterator
{
    private:
        stack<Node *> st;
        bool reversse = true;

    public:
        BSTiterator(Node *root, bool rev)
        {
            reversse = rev;
            pushall(root);
        }

        int next()
        {
            Node *temp = st.top();
            st.pop();
            if (!reversse)
                pushall(temp->right);
            else
                pushall(temp->left);

            return temp->data;
        }

        bool hasnext() { return !st.empty(); }

        void pushall(Node *root)
        {
            while (root)
            {
                st.push(root);
                if (reversse)
                    root = root->right;
                else
                    root = root->left;
            }
        }
};

bool findTarget(Node *root, int k)
{
    BSTiterator l(root, false);
    BSTiterator r(root, true);

    int i = l.next();
    int j = r.next();

    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
            i = l.next();
        else
            j = r.next();
    }

    return false;
}

int main()
{

    return 0;
}
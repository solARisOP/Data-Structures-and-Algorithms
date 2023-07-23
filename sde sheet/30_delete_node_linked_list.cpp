#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vp vector<pii>

class Node
{
public:
    int val;
    Node *next;

    Node() : val(0), next(NULL) {}
    Node(int x) : val(x), next(NULL) {}
    Node(int x, Node *nxt) : val(x), next(nxt) {}
};

void deleteNode(Node *node)
{
    node->val = node->next->val;
    Node *del = node->next;
    node->next = node->next->next;
    delete (del);
}

int main()
{

    return 0;
}
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

// iterative
Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    return prev;
}

// recursive
Node *solve(Node *head, Node *prev)
{
    Node *nxt = head->next;
    head->next = prev;
    prev = head;
    return (nxt) ? solve(nxt, prev) : head;
}

Node *reverseList_(Node *head)
{
    if (!head)
        return head;
    return solve(head, NULL);
}

int main()
{

    return 0;
}
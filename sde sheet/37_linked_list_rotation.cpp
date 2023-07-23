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

int ll_len(Node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *rotateRight(Node *head, int k)
{
    int len = ll_len(head);
    if (!head || !head->next || k % len == 0)
        return head;

    int rots = k;
    if (len < k)
        rots = k % len;

    Node *newhead = head;
    for (int i = 0; i < (len - rots) - 1; i++)
    {
        newhead = newhead->next;
    }

    Node *x = newhead;
    newhead = newhead->next;
    x->next = NULL;
    x = newhead;

    while (x->next)
    {
        x = x->next;
    }

    x->next = head;
    return newhead;
}

int main()
{

    return 0;
}
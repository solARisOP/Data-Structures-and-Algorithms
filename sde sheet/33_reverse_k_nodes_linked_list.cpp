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

Node *solve(Node *head, int k)
{
    Node *x = head;
    int i = 0;
    while (i < k && x)
    {
        x = x->next;
        i++;
    }
    Node *dummy = NULL;
    if (x || i == k)
    {
        dummy = solve(x, k);
        Node *curr = head;
        Node *prev = NULL;

        while (curr != x)
        {
            Node *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = dummy;
        return prev;
    }
    return head;
}

Node *reverseKGroup(Node *head, int k)
{
    return solve(head, k);
}

int main()
{

    return 0;
}
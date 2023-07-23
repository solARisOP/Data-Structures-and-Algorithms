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

Node *removeNthFromEnd(Node *head, int n)
{
    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *slow = dummy;
    Node *fast = dummy;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *del = slow->next;
    slow->next = slow->next->next;
    delete (del);

    return dummy->next;
}

int main()
{

    return 0;
}
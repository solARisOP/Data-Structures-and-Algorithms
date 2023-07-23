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

int len(Node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
Node *getIntersectionNode(Node *headA, Node *headB)
{
    int lenA = len(headA);
    int lenB = len(headB);

    Node *h1 = headA;
    Node *h2 = headB;
    if (lenB > lenA)
    {
        h1 = headB;
        h2 = headA;
    }

    int diff = abs(lenA - lenB);

    while (diff--)
        h1 = h1->next;
    while (h1 != h2)
    {
        h1 = h1->next;
        h2 = h2->next;
    }

    return h1;
}

int main()
{

    return 0;
}
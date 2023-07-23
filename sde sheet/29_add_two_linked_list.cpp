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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *head = dummy;

    int carry = 0;
    while (l1 || l2 || carry)
    {
        int num = 0;
        if (l1)
        {
            num += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            num += l2->val;
            l2 = l2->next;
        }
        num += carry;

        Node *nxt = new Node(num % 10);
        carry = num / 10;

        dummy->next = nxt;
        dummy = nxt;
    }

    return head->next;
}

int main()
{

    return 0;
}
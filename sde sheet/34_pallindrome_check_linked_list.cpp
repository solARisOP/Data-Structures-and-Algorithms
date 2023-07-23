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

bool isPalindrome(Node *head)
{
    if(head == NULL || head->next == NULL) return 1;
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *prev = slow;
    Node *curr = slow->next;

    while (curr)
    {
        Node *x = curr->next;
        curr->next = prev;
        prev = curr;
        curr = x;
    }

    while (head->val == prev->val && head != prev && head->next != prev)
    {
        head = head->next;
        prev = prev->next;
    }

    return head->val == prev->val;
}

int main()
{
    Node *a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(2);
    a->next->next->next = new Node(1);
    cout << isPalindrome(a);
    return 0;
}
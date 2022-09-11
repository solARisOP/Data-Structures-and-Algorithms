#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

bool isPalindrome(Node *head)
{
    if (head->next == NULL) return 1;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = slow;
    Node *nxt = NULL;
    Node *curr = slow->next;

    while (curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }

    Node *rev = prev;
    while (rev != head && rev->next != head)
    {
        if (head->data != rev->data) return 0;

        rev = rev->next;
        head = head->next;
    }
    return (head->data == rev->data) ? 1 : 0;
}

int main()
{

    return 0;
}
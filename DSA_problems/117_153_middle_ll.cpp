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
void printlist(Node *n)
{
    while (n)
    {
        cout << n->data << "  ";
        n = n->next;
    }
    cout << endl;
}

Node *mid_ll(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    printlist(mid_ll(head));

    return 0;
}
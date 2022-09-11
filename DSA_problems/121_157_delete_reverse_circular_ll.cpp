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

void deleteNode(Node **head, int key)
{
    // Your code goes here
    Node *del = (*head)->next;
    Node *chan = *head;
    while (del)
    {
        if (del->data == key)
        {
            chan->next = del->next;
            delete (del);
            break;
        }
        del = del->next;
        chan = chan->next;
    }
}

void reverse(Node **head)
{
    Node *prev = *head;
    Node *nxt = NULL;
    Node *curr = (*head)->next;

    while (curr != *head)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    (*head)->next = prev;
    *head = prev;
}

int main()
{

    return 0;
}
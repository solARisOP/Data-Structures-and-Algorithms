#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

Node *addOne(Node *head)
{

    Node *prev = NULL;
    Node *c = head;
    Node *trial = head;
    int cnt = 0;
    while (trial != NULL)
    {
        cnt++;
        trial = trial->next;
    }
    if (cnt == 1)
    {
        head->data += 1;
        return head;
    }

    while (c != NULL)
    {
        Node *n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }
    head = prev;

    int carry = 0;
    prev->data = prev->data + 1;
    carry = prev->data / 10;
    if (carry != 0)
        prev->data = prev->data % 10;
    prev = prev->next;

    while (prev != NULL && prev->next != NULL && carry != 0)
    {
        prev->data = (prev->data) + carry;
        carry = prev->data / 10;
        if (carry != 0)
        {
            prev->data = prev->data % 10;
        }
        prev = prev->next;
    }

    prev->data = (prev->data) + carry;
    prev = NULL;
    c = head;

    while (c != NULL)
    {
        Node *n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }

    return prev;
}

int main()
{

    return 0;
}
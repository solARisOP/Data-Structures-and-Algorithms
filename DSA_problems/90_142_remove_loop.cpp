#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void removeLoop(Node *head)
{
    Node *i = head;
    Node *j = head;

    while (j != NULL && j->next != NULL)
    {
        i = i->next;
        j = j->next->next;

        if (i == j) break;
    }

    if (i != j) return;

    i = head;

    Node *p = j;
    while (i != j)
    {
        i = i->next;
        p = j;
        j = j->next;
    }
    while (j->next != i)
    {
        j = j->next;
    }

    j->next = NULL;
    return;
}

int main()
{

    return 0;
}
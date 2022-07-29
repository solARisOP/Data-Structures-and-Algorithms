#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

bool detectLoop(Node *head)
{
    Node *i = head;
    Node *j = head;
    while (j != NULL && j->next != NULL)
    {
        i = i->next;
        j = j->next->next;
        if (i == j)return true;
    }

    return false;
}

int main()
{

    return 0;
}
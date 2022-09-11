#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int a)
    {
        data = a;
        next = NULL;
        prev = NULL;
    }
};

void tripletsum(Node *head, int x)
{
    Node *begin = head;
    while (begin && begin->next && begin->next->next)
    {
        Node *first = begin;
        Node *last = begin;
        while (last)
        {
            last = last->next;
        }

        while (first != last)
        {
            if (begin->data + first->data + last->data == x)
            {
                cout << begin->data << " " << first->data << " " << last->data << endl;
                int a = first->data, b = last->data;

                while (first->data == a && first != last)
                {
                    first = first->next;
                }

                while (last->data == b && last != first)
                {
                    last = last->prev;
                }
            }

            else if (first->data + last->data < x)
            {
                first = first->next;
            }

            else last = last->prev;
        }

        int c = begin->data;
        while (begin && begin->data == c) begin = begin->next;
    }
}

int main()
{

    return 0;
}
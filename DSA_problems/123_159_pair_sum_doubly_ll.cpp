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

void pairsum(Node*head, int x)
{
    Node *first = head;
    Node*last = head;
    while(last)
    {
        last = last->next;
    }

    while(first!=last)
    {
        if(first->data + last->data == x)
        {
            cout<<first->data<<" "<<last->data<<endl;
            int a = first->data, b = last->data;

            while(first ->data == a && first != last)
            {
                first = first ->next;
            }

            while(last ->data == b && last != first)
            {
                last = last ->prev;
            }

        }

        else if(first->data + last->data < x)
        {
            first = first ->next;
        }

        else last = last ->prev;
    }

}

int main()
{
    
    return 0;
}
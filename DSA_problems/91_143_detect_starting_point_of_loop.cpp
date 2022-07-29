#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node * next;
};

void detect_loop(node *head)
{
    node *i = head;
    node *j = head;

    while(j != NULL && j->next != NULL)
    {
        i = i->next;
        j = j ->next->next;

        if(i == j) {break;}
    }

    if(i != j) cout<<"no loop";

    i = head;
    while(i != j)
    {
        i = i->next;
        j = j->next;
    }

    cout<<i->data;

}

int main()
{
    
    return 0;
}
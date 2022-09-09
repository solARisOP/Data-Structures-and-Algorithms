#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int a)
        {
            data= a;
            next = NULL;
        }
};

int len(Node* a)
{
    int cnt_a = 0;
    while(a)
    {
        a=a->next;
        cnt_a++;
    }
    return cnt_a;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int a = len(head1);
    int b = len(head2);
    
    if(a>b)
    {
        while(a!=b)
        {
            head1=head1->next;
            a--;
        }
        
    }
    else if(a<b)
    {
        while(a!=b)
        {
            head2=head2->next;
            b--;
        }
        
    }
    
    while(head1 != head2)
    {
        head1=head1->next;
        head2=head2->next;
    }
    
    return head1->data;
}

int main()
{
    
    return 0;
}
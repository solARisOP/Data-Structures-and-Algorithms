#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data = new_data;
 
    new_node->prev = NULL;
 
    new_node->next = (*head_ref);
 
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void printList(Node* head)
{
    if (head == NULL) cout << "Doubly Linked list empty";
 
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* rrr(Node * head)
{
    Node *i = head;
    i->data = 100;
    return head;
}

Node* sortAKSortedDLL(Node* head, int k)
{
    Node*i;
    Node*s = i->next;
    Node*ans = head;
    for(i = head->next; i!= NULL; i= s)
    {
        s=i->next;
        Node* j = i->prev;
        int flag = 0; 
        while(j!= NULL && i->data < j->data)
        {
            Node*temp = j->prev;
            Node*temp2 = i->next;

            if(flag == 0) 
                flag++;
                s = temp2;

            i->prev = temp;
            if(temp != NULL ) temp->next = i;
            i->next = j;
            j->prev  = i;
            j->next = temp2;
            if(temp2 != NULL ) temp2->prev = j;
            j = temp;
        }
        flag =0;
    }
    while(ans->prev != NULL )
    {
        ans = ans->prev;
    }
    return ans;
}


int main()
{
    Node* head = NULL;
 
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
 
    int k = 2;
 
    cout << "Original Doubly linked list:\n";
    printList(head);

    head = sortAKSortedDLL(head,k);
 
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);
 
    return 0;
    return 0;
}
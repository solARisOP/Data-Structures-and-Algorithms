#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next; // we are updating the pointer to the next object.
    }
    cout << endl;
}

node *insertionatfirst(node *head, int element)
{
    node *ptr = new node(); // if we dont assign it with dyanamic memory it will be out of scope when we return ptr.
    ptr->next = head;
    ptr->data = element;
    //*head = *ptr; if we write this below(by making it void) than it will start an infinite loop because above we have assigned ptr->next = head;
    return ptr; //because in main function we are updating head
    // we can make it a void function too by passing head as a refrence, and whatever changes we make here it will reflect. 
}

node *insertatindex(node *head, int element, int index)
{
    node *ptr = new node();
    node *p = head;

    int i = 0;
    while(i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = element;
    ptr->next= p->next;
    p->next = ptr;
    return head;
}

// The above function can also be written as below

// void insertatindex(node *head, int element, int index)
// {
//     node *ptr = new node();
//     node *p = head;
// 
//     int i = 0;
//     while(i != index-1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = element;
//     ptr->next= p->next;
//     p->next = ptr;
// }

// The above function can also be written as below and in the function call we have to send refrence of the head(&head).

// void insertatindex(node **head, int element, int index)
// {
//     node *ptr = new node();
//     node *p = *head;
// 
//     int i = 0;
//     while(i != index-1)
//     {
//         p = p->next;
//         i++;
//     }
//     ptr->data = element;
//     ptr->next= p->next;
//     p->next = ptr;
// }


node *insertatend(node *head, int element)
{
    node *ptr = new node();
    ptr->data = element;  
    node *p = head;               ;
    while( p->next !=NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node *insertafternode(node *head, node *cnode, int element)
{
    node *ptr = new node();
    ptr->data = element;
    ptr -> next = cnode->next;
    cnode->next = ptr;
    return head;
}  

int main()
{
    node *head = new node(); // we are taking memory from heap.
    node *second = new node();
    node *third = new node();

    // link first and second nodes
    head->data = 90;
    head->next = second; // we are pointing to second object from the help of next pointer we created in the structure.

    // link second and third nodes
    second->data = 31;
    second->next = third;

    // terminate the list and third node
    third->data = 50;
    third->next = NULL;

    traversal(head); // we are sending first pointer to the function
    head = insertionatfirst(head, 89); // here we are updating the head.
    // head = insertatindex(head, 6, 2);
    // head = insertatend(head, 89);
    // head = insertafternode(head, second, 62);
    traversal(head);
    

    return 0;
}
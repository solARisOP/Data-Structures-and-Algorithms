#include <iostream>
using namespace std;

typedef struct Node
{

    int data;
    struct Node *next; // here next is a struct node pointer which points,
    // to a data type(object) of struct node type. In short its called self referencing structure.
} node;

void traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element : " << ptr->data << endl;
        ptr = ptr->next; // we are updating the pointer to the next object.
    }
}

int main()
{
    node *head = new node; // we are taking memory from heap.
    node *second = new node;
    node *third = new node;

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
}
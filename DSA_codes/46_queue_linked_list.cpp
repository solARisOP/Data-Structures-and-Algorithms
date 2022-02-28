#include <iostream>
using namespace std;

class queue
{
    public:
        int data;
        queue*next;
};

queue *f  = NULL;
queue *r = NULL;

void traversal(queue *p)
{
    cout<<"printing elements of the list"<<endl;
    while(p != NULL)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

void dequeue()
{
    int val  = -1;
    queue *ptr = f;
    if(f == NULL)
    {
        cout<<"Queue is empty"<<endl;
        cout<<"Dequeuing element "<<val<<endl;
    }
    else
    {
        val = ptr->data;
        f = f->next;
        delete(ptr);
        cout<<"Dequeuing element "<<val<<endl;
    }
}

void enqueue(int element)
{
    queue *n = new queue();
    if(n == NULL)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
        n->data = element;
        n->next = NULL;
        if(f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int main()
{
    traversal(f);

    enqueue(5);
    enqueue(53);
    enqueue(65);
    enqueue(46);
    enqueue(12);
    enqueue(89);
    enqueue(90);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    traversal(f);


    return 0;
}
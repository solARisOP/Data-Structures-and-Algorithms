#include <iostream>
using namespace std;

class circularqueue
{
    public:
        int size;
        int f;
        int r;
        int *arr;
};

circularqueue *q = new circularqueue ();

int isempty()
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isfull()
{
    if((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(int element)
{
    if(isfull())
    {
        cout<<"CircularQueue is full"<<endl;
    }
    else
    {
        q->r = (q->r+1) % q->size ;
        q->arr[q->r] = element;
        cout<<"element enqueued in circular queue is "<<element<<endl;
    }
}

int dequeue()
{
    int a = -1;
    if(isempty())
    {
        cout<<"CircularQueue is empty"<<endl;
    }
    else
    {
        q->f = (q->f+1) % q->size; // this is the increment of f.
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    q->size = 4;// we have to take +1 than the size you desire, because our f and r have to be 0 initially and our last space cannot be filled.
    q->f = q->r = 0;
    q->arr = new int [q->size];

    enqueue(12);
    enqueue(34);
    enqueue(86);
    // enqueue(7); //not more than 3 element can be inserted as 1 space needs to be empty

    if(isfull())
    {
        cout<<"CircularQueue is full"<<endl;
    }

    cout<<"The element removed from the circularqueue is "<<dequeue()<<endl;
    cout<<"The element removed from the circularqueue is "<<dequeue()<<endl;
    cout<<"The element removed from the circularqueue is "<<dequeue()<<endl;

    enqueue(78);
    enqueue(78);
    enqueue(78);

    if(isempty())
    {
        cout<<"CircularQueue is empty"<<endl;
    }
    return 0;
}
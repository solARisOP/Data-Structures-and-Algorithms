#include <iostream>
using namespace std;

class queue
{
    public:
        int size;
        int f;
        int r;
        int *arr;
};

queue *q = new queue ();

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
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int element)
{
    if(isfull())
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = element;
    }
}

int dequeue()
{
    int a = -1;
    if(isempty())
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    q->size = 3;
    q->f = q->r = -1;
    q->arr = new int [q->size];

    // if(isempty())
    // {
    //     cout<<"Queue is empty"<<endl;
    // }

    enqueue(12);
    enqueue(34);
    enqueue(86);

    if(isfull())
    {
        cout<<"Queue is full"<<endl;
    }

    cout<<"The element removed from the queue is "<<dequeue()<<endl;
    cout<<"The element removed from the queue is "<<dequeue()<<endl;
    cout<<"The element removed from the queue is "<<dequeue()<<endl;

    if(isempty())
    {
        cout<<"Queue is empty"<<endl;
    }
    

    return 0;
}
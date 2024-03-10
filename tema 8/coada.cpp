#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *link;
} *front, *rear;

QueueNode *CreateNew(int val)
{
    QueueNode *n=new QueueNode;
    n->data=val;
    n->link=NULL;
    return n;
}
int isQueueEmpty()
{
    return front==NULL;
}
int frontElement()
{
    if(isQueueEmpty()) return -1;
    return front->data;
}
void enqueue(int val)
{
    QueueNode *q=CreateNew(val);
    if(isQueueEmpty()) rear=front=q;
    else
    {
        rear->link=q;
        rear=q;
    }
}
int dequeue()
{
    if (isQueueEmpty()) return -1;
    QueueNode *p=front;
    front=front->link;
    if (front==NULL) rear=NULL;
    int removed=p->data;
    return removed;
}
void displayQueue()
{
    if(front==NULL) cout<<"Queue is Empty"<<endl;
    else
    {
        QueueNode *p=front;
        cout<<"Out: ";
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->link;
        }
        cout<<":In"<<endl;
    }
}
int searchElement(int val)
{
    QueueNode *p=front;
    int count=1;
    while(p!=NULL)
    {
        if(p->data==val) return count;
        count++;p=p->link;
    }
    return -1;
}

int main()
{
    displayQueue();
    enqueue(1); enqueue(2); enqueue(3);
    displayQueue();
    cout<<searchElement(2)<<endl;
    cout<<searchElement(4)<<endl;
    cout<<isQueueEmpty()<<endl;
    cout<<dequeue()<<endl;
    displayQueue();
    cout<<frontElement()<<endl;
    displayQueue();
    dequeue();dequeue();
    displayQueue();
    cout<<dequeue()<<endl<<isQueueEmpty()<<endl;

    return 0;
}

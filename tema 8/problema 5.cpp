#include <iostream>
using namespace std;
int img[100][100], imgSize;
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
void color(int i, int j, int c)
{
    img[i][j]=c;
    if(img[i][j+1]==1 && j+1<imgSize)  {enqueue(img[i][j+1]); color(i, j+1, c); dequeue();}
    if(img[i][j-1]==1 && j-1>=0) {enqueue(img[i][j-1]); color(i, j-1, c); dequeue();}
    if(img[i+1][j]==1 && i+1<imgSize)  {enqueue(img[i+1][j]); color(i+1, j, c); dequeue();}
    if(img[i-1][j]==1 && i-1>=0) {enqueue(img[i-1][j]); color(i-1, j, c); dequeue();}
}

int main()
{
    int i, j, c=2;
    cout<<"imgSize: ";cin>>imgSize;
    for(i=0; i<imgSize; i++)
        for(j=0; j<imgSize; j++) cin>>img[i][j];
    for(i=0; i<imgSize; i++)
        for(j=0; j<imgSize; j++)
            if(img[i][j]==1)
            {
                enqueue(img[i][j]);
                color(i, j, c);
                dequeue();
                if(isQueueEmpty()) c++;
            }

    cout<<endl;
    for(i=0; i<imgSize; i++)
    {
        for(j=0; j<imgSize; j++) cout<<img[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *link;
} *top;

StackNode *CreateNew(int val)
{
    StackNode *n=new StackNode;
    n->data=val;
    n->link=NULL;
    return n;
}
int isStackEmpty()
{
    return top==NULL;
}
int topElement()
{
    if(isStackEmpty()) return -1;
    return top->data;
}
void pushElement(int val)
{
    StackNode *n=CreateNew(val);
    n->link=top;
    top=n;
}
int popElement()
{
    if (isStackEmpty()) return -1;
    StackNode *n=top;
    top=top->link;
    int removed=n->data;
    return removed;
}
void displayStack()
{
    if(top==NULL) cout<<"Stiva e goala"<<endl;
    else
    {
        StackNode *p=top;
        cout<<"Top: ";
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->link;
        }
        cout<<":Bottom"<<endl;
    }
}
int searchElement(int val)
{
    StackNode *p=top;
    int count=0;
    while(p!=NULL)
    {
        if(p->data==val) return count;
        count++;p=p->link;
    }
    return -1;
}

int main()
{
    displayStack();
    pushElement(1); pushElement(2); pushElement(3);
    displayStack();
    cout<<searchElement(2)<<endl;
    cout<<searchElement(4)<<endl<<isStackEmpty()<<endl<<popElement()<<endl;
    displayStack();
    cout<<topElement()<<endl;
    displayStack();
    popElement();popElement();
    displayStack();
    cout<<popElement()<<endl<<isStackEmpty()<<endl;

    return 0;
}

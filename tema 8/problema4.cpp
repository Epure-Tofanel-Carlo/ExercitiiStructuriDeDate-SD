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
    if (isStackEmpty())
        return -1;
    StackNode *n=top;
    top=top->link;
    int removed=n->data;
    return removed;
}

int main()
{
    int i, num, pair[100];
    cout << "Numar de tarusi:";
    cin >> num;
    for(i=0 ; i<num ; i++)
        cin>>pair[i];
    for(i=0 ; i<num ; i++)
        if(isStackEmpty())
            pushElement(pair[i]);
        else
            if(pair[i]==topElement())
                popElement();
        else pushElement(pair[i]);
    if(isStackEmpty())
        cout<<"Valid Configuration";
    else
        cout<<"Invalid Configuration";


    return 0;
}

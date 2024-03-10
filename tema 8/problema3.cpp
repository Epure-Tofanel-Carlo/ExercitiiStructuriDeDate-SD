#include <iostream>
#include <cstring>
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

int main()
{
    char str[100];
    cin.getline(str,100);
    int i, valid=1;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='(') pushElement(1);
        else if(popElement()==-1)
        {
            valid=0;
            break;
        }

    }
    if(valid==0 || isStackEmpty()==0)
        cout<<"Incorrect";
    else cout<<"Correct";


    return 0;
}

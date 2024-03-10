#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next, *prev;
};

void insertFirst(Node *&P, Node *&U, int x)
{
    Node *newNode = new Node;
    newNode->info = x;
    newNode->prev = NULL;
    newNode->next = P;

    if (!P && !U)
        U = newNode;
    else
        P->prev = newNode;

    P = newNode;
}

void insertLast(Node *&P, Node *&U, int x)
{
    Node *newNode = new Node;
    newNode->info = x;
    newNode->next = NULL;
    newNode->prev = U;

    if (!P && !U)
        P = newNode;
    else
        U->next = newNode;

    U = newNode;
}

void deleteFirst(Node *&P, Node *&U)
{
    if (P == U)
        P = U = NULL;
    else if (P && U)
    {
        P = P->next;
        P->prev = NULL;
    }
}

void deleteLast(Node *&P, Node *&U)
{
    if (P == U)
        P = U = NULL;
    else if (P && U)
    {
        U = U->prev;
        U->next = NULL;
    }
}

void deleteAtPositionK(Node *&P, Node *&U, int k)
{
    int i;
    Node *temp = P;

    for (i = 1; i < k; i++)
        temp = temp->next;

    if (temp == P)
        deleteFirst(P, U);
    else if (temp == U)
        deleteLast(P, U);
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
}

void displayForward(Node *p)
{
    if (p)
    {
        cout << p->info << " ";
        displayForward(p->next);
    }
}

void displayBackward(Node *p)
{
    if (p)
    {
        cout << p->info << " ";
        displayBackward(p->prev);
    }
}

int main()
{
    Node *head, *tail;
    head = tail = NULL;

    int n, k, i;
    cout << "Numarul de elemente: ";
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> k;
        insertFirst(head, tail, k);
    }

    cout << "Lista de la inceput: ";
    displayForward(head);
    cout << endl;

    cout << "Lista de la final: ";
    displayBackward(tail);
    cout << endl;

    return 0;
}

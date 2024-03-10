#include <iostream>
using namespace std;

struct QueueNode
{
    int info;
    QueueNode *next;
};
struct Queue
{
    QueueNode *front, *rear;
};
QueueNode *newNode(int x)
{
    QueueNode *n = new QueueNode;
    n->info = x;
    n->next = NULL;
    return n;
}
Queue *newQueue()
{
    Queue *q = new Queue;
    q->front = q->rear = NULL;
    return q;
}
int isEmpty(Queue *q)
{
    return q->front == NULL;
}
void enqueue(Queue *q, int x)
{
    QueueNode *n = newNode(x);
    if (isEmpty(q))
        q->front = q->rear = n;
    else
    {
        q->rear->next = n;
        q->rear = n;
    }
}
int dequeue(Queue *q)
{
    if (isEmpty(q)) return -1;
    QueueNode *n = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    return n->info;
}
void getMax(Queue *CC[100], int k, int &maxi, int &p)
{
    int i, x;
    for (i = 1; i <= k; i++)
    {
        x = CC[i]->rear->info;
        if (maxi < x) maxi = x, p = i;
    }
}
void display(Queue *q)
{
    if (isEmpty(q)) cout << "Empty Queue" << endl;
    else
    {
        QueueNode *p = q->front;
        cout << "Out: ";
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->next;
        }
        cout << ":In" << endl;
    }
}

int main()
{
    int n, i, j, k, x, ok = 1, nr = 0;
    cout << "N: "; cin >> n;
    cout << "K: "; cin >> k;
    Queue *CI = newQueue();
    cout << "Introdu vagoanele de la 1 la N: ";
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        enqueue(CI, x);
    }
    Queue *CC[100];
    for (i = 1; i <= k; i++)
    {
        CC[i] = newQueue();
        enqueue(CC[i], 0);
    }  // Create the auxiliary queues
    Queue *CF = newQueue();
    for (i = 1; i <= n; i++)
    {
        x = dequeue(CI);
        j = 1;
        while (j <= k && CC[j]->rear->info > x) j++;
        if (j > k) { ok = 0; break; }
        else enqueue(CC[j], x);
    }
    if (ok == 0) cout << "Strategie invalida";
    else
    {
        for (i = 1; i <= k; i++)
            if (CC[i]->front == CC[i]->rear) nr++;
        k = k - nr;
        for (i = 1; i <= n; i++)
        {
            int maxi = 0, p = 0;
            getMax(CC, k, maxi, p);
            enqueue(CF, maxi);

            QueueNode *q = CC[p]->front, *last;
            while (q->next != NULL)
            {
                last = q;
                q = q->next;
            }
            last->next = NULL;
            CC[p]->rear = last;
            delete q;
        }
        display(CF);
    }

    return 0;
}

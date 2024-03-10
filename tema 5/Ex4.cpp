#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* head1 = nullptr;
Node* head2 = nullptr;

void insertSorted(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void interclaseaza(Node* &head1, Node* &head2) {
    Node* current1 = head1;
    Node* current2 = head2;
    Node* temp;

    if (current1 == nullptr || (current2 != nullptr && current2->data < current1->data)) {
        head1 = current2;
        temp = current2->next;
        current2->next = current1;
        current2 = temp;
    }

    while (current1 != nullptr && current2 != nullptr) {
        while (current1->next != nullptr && current1->next->data < current2->data) {
            current1 = current1->next;
        }
        temp = current2->next;
        current2->next = current1->next;
        current1->next = current2;
        current1 = current1->next;
        current2 = temp;
    }
}

void afisareLista(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n, m, val;

    cout << "nr elemente lista 1: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "element lista 1:";
        cin >> val;
        insertSorted(head1, val);
    }

    cout << "nr elemente lista 2: ";
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cout << "element lista 2: ";
        cin >> val;
        insertSorted(head2, val);
    }

    cout << "prima lista:";
    afisareLista(head1);
    cout << endl;

    cout << "a doua lista: ";
    afisareLista(head2);
    cout << endl;

    interclaseaza(head1, head2);

    cout << "lista interclasata: ";
    afisareLista(head1);
    cout << endl;

    return 0;
}
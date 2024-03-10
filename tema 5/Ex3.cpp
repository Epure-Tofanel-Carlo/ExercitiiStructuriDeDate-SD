#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* head = nullptr;

void append(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void inverseazaLista() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void afisareLista() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n, val;

    cout << "nr elemente: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "element lista: ";
        cin >> val;
        append(val);
    }

    cout << "lista initiala era: ";
    afisareLista();
    cout << endl;

    inverseazaLista();

    cout << "lista acum este: ";
    afisareLista();

    return 0;
}
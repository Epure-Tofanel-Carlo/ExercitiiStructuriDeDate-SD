#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* head = nullptr;

void insertSorted(int data) {
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
        insertSorted(val);
        cout << "lista sortata: ";
        afisareLista();
        cout << endl;
    }

    return 0;
}
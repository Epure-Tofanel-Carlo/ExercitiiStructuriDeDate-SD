#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
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

    void insertMediiAritmetice() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            int media = (current->data + current->next->data) / 2;
            Node* newNode = new Node(media);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
    }

    void afisareLista() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList lista;
    int n, val;

    cout << "nr elemente: ";
    cin >> n;

    for (int i = 0; i < n; i++ ) {
        cout << "element lista: ";
        cin >> val;
        lista.append(val);
    }

    lista.insertMediiAritmetice();
    lista.afisareLista();

    return 0;
}
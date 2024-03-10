#include <iostream>
#include <string>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void append(Node*& head, int data) {
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


Node* add(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* current1 = head1;
    Node* current2 = head2;
    int carry = 0, sum;

    while (current1 != nullptr || current2 != nullptr) {
        sum = carry + (current1 ? current1->data : 0) + (current2 ? current2->data : 0);
        carry = sum / 10;
        append(result, sum % 10);

        if (current1) current1 = current1->next;
        if (current2) current2 = current2->next;
    }

    if (carry > 0) {
        append(result, carry);
    }

    return result;
}


void afisareLista(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node* CreazaListaDinNumar(const string& numar) {
    Node* lista = nullptr;
    for (int i = numar.size() - 1; i >= 0; --i) {
        append(lista, numar[i] - '0');
    }
    return lista;
}

int main() {
    string numar1, numar2;

    cout << "primul nr mare: ";
    cin >> numar1;

    cout << "al doilea numar mare: ";
    cin >> numar2;

    Node* lista1 = CreazaListaDinNumar(numar1);
    Node* lista2 = CreazaListaDinNumar(numar2);

    Node* rezultat = add(lista1, lista2);

    cout << "rezultatul adunarii este: ";
    afisareLista(rezultat);
    cout << endl;

    return 0;
}
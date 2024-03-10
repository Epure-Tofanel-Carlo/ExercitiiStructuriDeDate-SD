#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertFirst(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

Node* inmulteste(Node* head, int numar) {
    Node* rezultat = nullptr;
    Node* current = head;
    int carry = 0, produs;

    while (current != nullptr) {
        produs = carry + current->data * numar;
        carry = produs / 10;
        insertFirst(rezultat, produs % 10);
        current = current->next;
    }

    if (carry > 0) {
        insertFirst(rezultat, carry);
    }

    return rezultat;
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
        insertFirst(lista, numar[i] - '0');
    }
    return lista;
}

int main() {
    string numarMare;
    int numarMic;

    cout << "nr mare: ";
    cin >> numarMare;

    cout << "nr mic (o singura cifra): ";
    cin >> numarMic;

    Node* lista = CreazaListaDinNumar(numarMare);

    Node* rezultat = inmulteste(lista, numarMic);

    cout << "rezultatul inmultirii este: ";
    afisareLista(rezultat);
    cout << endl;

    return 0;
}
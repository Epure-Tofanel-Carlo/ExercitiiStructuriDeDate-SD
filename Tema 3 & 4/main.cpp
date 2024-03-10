#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* prim;
    Node* ultim;
public:
    LinkedList() {
        prim = nullptr;
        ultim = nullptr;
    }

    void adi(int valoare) {
        Node* nou = new Node;
        nou->data = valoare;
        nou->next = prim;
        prim = nou;
        if (ultim == nullptr) {
            ultim = nou;
        }
    }

    void adf(int valoare) {
        Node* nou = new Node;
        nou->data = valoare;
        nou->next = nullptr;
        if (ultim == nullptr) {
            prim = nou;
        } else {
            ultim->next = nou;
        }
        ultim = nou;
    }

    void af() {
        Node* p = prim;
        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int cv(int valoare) {
        int pozitie = 1;
        Node* p = prim;
        while (p != nullptr) {
            if (p->data == valoare) {
                return pozitie;
            }
            p = p->next;
            pozitie++;
        }
        return -1;
    }

    int cp(int pozitie) {
        int contor = 1;
        Node* p = prim;
        while (p != nullptr) {
            if (contor == pozitie) {
                return p->data;
            }
            p = p->next;
            contor++;
        }
        return -1;
    }

    void iv(int valoare, int noua_valoare) {
        Node* p = prim;
        while (p != nullptr) {
            if (p->data == valoare) {
                Node* nou = new Node;
                nou->data = noua_valoare;
                nou->next = p->next;
                p->next = nou;
                if (p == ultim) {
                    ultim = nou;
                }
                break;
            }
            p = p->next;
        }
    }

};

int main() {

    LinkedList lista;
    lista.adi(1);
    lista.adi(2);
    lista.adi(3);
    lista.af();
    lista.adf(4);
    lista.af();
    cout << lista.cv(5) << " ";
    cout << lista.cv(1) << " ";
    cout << lista.cv(4) << " ";
    cout << lista.cp(5) << " ";
    cout << lista.cp(3) << " " << endl;
    lista.iv(2, 5);
    lista.af();
    lista.iv(4, 6);
    lista.af();
    lista.iv(10, 7);
    lista.af();

    return 0;
}
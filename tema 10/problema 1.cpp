#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void displayNodesAtLevel(Node *root, int level, int currentLevel)
{
    if (root == NULL)
        return;

    if (currentLevel == level)
    {
        cout << root->data << " ";
        return;
    }

    displayNodesAtLevel(root->left, level, currentLevel + 1);
    displayNodesAtLevel(root->right, level, currentLevel + 1);
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int level;
    cout << "Introdu nivelul K: ";
    cin >> level;

    cout << "Nodurile de la nivelul " << level << ": ";
    displayNodesAtLevel(root, level, 0);
    cout << endl;

    return 0;
}

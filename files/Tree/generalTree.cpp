#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *firstChild;
    Node *nextSibling;

    Node(int val)
    {
        data = val;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

// Example usage
int main()
{
    Node *root = new Node(1);

    root->firstChild = new Node(2);                           // first child of root
    root->firstChild->nextSibling = new Node(3);              // sibling of 2
    root->firstChild->nextSibling->nextSibling = new Node(4); // sibling of 3

    root->firstChild->firstChild = new Node(5); // child of 2

    cout << "Root: " << root->data << endl;
    cout << "First Child: " << root->firstChild->data << endl;
    cout << "Next Sibling of First Child: " << root->firstChild->nextSibling->data << endl;
}
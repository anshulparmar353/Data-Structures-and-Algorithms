#include <iostream>
using namespace std;

class AVLTree{
public:
    int data;
    int height;
    AVLTree *left;
    AVLTree *right;

    AVLTree(int val){
        data = val;
        height = 0;
        left = right = nullptr;
    }
};

int getHeight(AVLTree *node){
    return node ? node->height : -1;
}

int balFact(AVLTree *node){
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(AVLTree *node){
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

AVLTree *rotateLeft(AVLTree *root){

    AVLTree *newRoot = root->right;
    AVLTree *transferSubtree = newRoot->left;

    newRoot->left = root;
    root->right = transferSubtree;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

AVLTree *rotateRight(AVLTree *root){

    AVLTree *newRoot = root->left;
    AVLTree *transferSubtree = newRoot->right;

    newRoot->right = root;
    root->left = transferSubtree;

    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

AVLTree *insertInAVL(AVLTree *root, int val){

    if (root == NULL){
        return new AVLTree(val);
    }

    if (val < root->data){
        root->left = insertInAVL(root->left, val);
    }else if (val > root->data){
        root->right = insertInAVL(root->right, val);
    }else{
        return root;
    }

    updateHeight(root);

    int bf = balFact(root);

    //left-left case
    if (bf > 1 && val < root->left->data){
        return rotateRight(root);
    }

    //right-right case
    if (bf < -1 && val > root->right->data){
        return rotateLeft(root);
    }

    //left-right case
    if (bf > 1 && val > root->left->data){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    //right-left case
    if (bf < -1 && val < root->right->data){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

AVLTree *successorNode(AVLTree *root){

    while (root != nullptr && root->left != nullptr){
        root = root->left;
    }

    return root;
}

AVLTree *predecessorNode(AVLTree *root){

    while (root != nullptr && root->right != nullptr){
        root = root->right;
    }

    return root;
}

AVLTree *deleteNode(AVLTree *root, int val){

    if (root == nullptr){
        return nullptr;
    }

    if (val < root->data){
        root->left = deleteNode(root->left, val);
    }else if (val > root->data){
        root->right = deleteNode(root->right, val);
    }else{
        // root == val
        // for 0 child and 1 child
        if (root->left == nullptr){
            AVLTree *temp = root->right;
            delete (root);
            return temp;
        }else if (root->right == nullptr){
            AVLTree *temp = root->left;
            delete (root);
            return temp;
        }else{
            // for 2 child
            AVLTree *IS = successorNode(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }

        // Step 2: Update height
        updateHeight(root);

        // Step 3: Get balance factor
        int bf = balFact(root);

        // Step 4: Rebalance if needed

        // Left-Left Case
        if (bf > 1 && balFact(root->left) >= 0){
            return rotateRight(root);
        }

        // Left-Right Case
        if (bf > 1 && balFact(root->left) < 0){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right-Right Case
        if (bf < -1 && balFact(root->right) <= 0){
            return rotateLeft(root);
        }

        // Right-Left Case
        if (bf < -1 && balFact(root->right) > 0){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;
}

void inorder(AVLTree *root){

    if (root == nullptr){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    AVLTree *root = nullptr;

    root = insertInAVL(root, 10);
    root = insertInAVL(root, 20);
    root = insertInAVL(root, 30);
    root = insertInAVL(root, 25);
    root = insertInAVL(root, 28);
    root = insertInAVL(root, 27);
    root = insertInAVL(root, 5);

    cout << "Inorder Traversal of AVL Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
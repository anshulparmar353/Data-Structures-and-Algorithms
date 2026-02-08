#include <iostream>
#include<vector>
using namespace std;

enum Color{ RED,BLACK };
    
class Node{

public:
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val)
    {
        data = val;
        color = RED;
        left = right = parent = nullptr;
    }
};

class RBTTree{

private:
    Node *root = nullptr;

public:

    void leftRotate(Node* parentNode){

        Node* childNode = parentNode->right;
        parentNode->right = childNode->left;

        if(childNode->left != nullptr){
            childNode->left->parent = parentNode;
        }

        childNode->parent = parentNode->parent;

        if(parentNode->parent == nullptr){
            root = childNode;
        }else if (parentNode == parentNode->parent->left){
            parentNode->parent->left = childNode;
        }else{
            parentNode->parent->right = childNode;
        }

        childNode->left = parentNode;
        parentNode->parent = childNode;

    }

    void rightRotate(Node* parentNode){

        Node* childNode = parentNode->left;
        parentNode->left = childNode->right;

        if(childNode->right != nullptr){
            childNode->right->parent = parentNode;
        }

        childNode->parent = parentNode->parent;

        if(parentNode->parent == nullptr){
            root = childNode;
        }else if(parentNode == parentNode->parent->right){
            parentNode->parent->right = childNode;
        }else{
            parentNode->parent->left = childNode;
        }

        childNode->right = parentNode;
        parentNode->parent = childNode;
        
    }

    void insertFix(Node* newNode){

        while (newNode != root && newNode->parent->color == RED){
            
            Node* grandpa = newNode->parent->parent;

            // Case: Parent is left child of grandparent
            if(newNode->parent == grandpa->left){
                Node* uncle = grandpa->right;

                //Case 1: Uncle is RED recolor
                if(uncle != nullptr && uncle->color == RED){

                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandpa->color = RED;
                    //if any changes in the up of the tree
                    newNode = grandpa;

                }else{

                    //Case 2: newnode is right child (left rotate)
                    if(newNode == newNode->parent->right){
                        newNode = newNode->parent;
                        leftRotate(newNode);

                    }

                    //Case 3: newnode is left child (right rotate)
                    newNode->parent->color = BLACK;
                    grandpa->color = RED;   
                    rightRotate(grandpa);
                }

            } 
            // Mirror case: Parent is right child
            else{
                Node* uncle = grandpa->left;
                
                //if uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    newNode->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandpa->color = RED;
                    newNode = grandpa;

                }else{

                    //newnode is left child (right rotate)
                    if(newNode == newNode->parent->left){
                        newNode = newNode->parent;
                        rightRotate(newNode);
                    }

                    //newnode is right child (left rotate)
                    newNode->parent->color = BLACK;
                    grandpa->color = RED;
                    leftRotate(grandpa);

                }
            }    
        }

        root->color = BLACK;   
    }

    void insertNode(int val){
        
        Node* newNode = new Node(val);
        Node* current = root;
        Node* parentNode = nullptr;

        //step 1: insert as BST
        while(current != nullptr){
            parentNode = current;

            if(newNode->data > current->data){
                current = current->right;
            }else{
                current = current->left;
            }
        }

        newNode->parent = parentNode;

        if(parentNode == nullptr){
            //if tree is empty
            root = newNode;
            root->color = BLACK;
            return;
        }else if(newNode->data < parentNode->data){
            parentNode->left = newNode;
        }else{
            parentNode->right = newNode;
        }

        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->color = RED;

        // Step 2: Fix Red-Black Tree properties
        insertFix(newNode);
    }

    Node* inorderSuccessor(Node* root){

        while(root != nullptr && root->left != nullptr){
            root = root->left;
        }

        return root;
    }

    void transPlant(Node* deleteNode, Node* tranpNode){

        if(deleteNode->parent == nullptr){
            root = tranpNode;
        }else if( deleteNode == deleteNode->parent->left){
            deleteNode->parent->left = tranpNode;
        }else{
            deleteNode->parent->right = tranpNode;
        }

        if(tranpNode != nullptr){
            tranpNode->parent = deleteNode->parent;
        }
    }

    void deleteFix(Node* node){

        while(node != root && ( node == nullptr || node->color == BLACK)){

            if(node == node->parent->left){
                Node* sibling = node->parent->right;

                //Case 1: sibling is RED
                if(sibling != nullptr && sibling->color == RED){
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    leftRotate(node->parent);
                    sibling = node->parent->right;
                }

                //case 2: sibling is Black and both the child are Black
                if(( sibling->left == nullptr || sibling->left->color == BLACK ) &&
                    ( sibling->right == nullptr || sibling->right->color == BLACK)){

                    if(sibling != nullptr){
                        sibling->color = RED;
                        node = node->parent;
                    }

                }else{

                    //case 3: sibling is Black , left child is Red and right child is Black
                    if( sibling->right == nullptr || sibling->right->color == BLACK ){
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rightRotate(sibling);
                        sibling = node->parent->right;
                    }

                    //case 4: sibling is Black but right child is Red

                    if( sibling != nullptr){
                        sibling->color = node->parent->color;
                        node->parent->color = BLACK;
                    }

                    if( sibling->right != nullptr ){
                        sibling->right->color = BLACK;
                        leftRotate(node->parent);
                        node = root;
                    }

                }
            }  
            else{
                //Mirrot case when the node is right child
                Node* sibling = node->parent->left;

                //Case 1: sibling is Red
                if(sibling != nullptr && sibling->color == RED){
                    sibling->color = BLACK;
                    node->parent->color = RED;
                    rightRotate(node->parent);
                    sibling = node->parent->left;
                }

                //case 2: sibling is Black and both child is Black
                if((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK)){

                        if(sibling != nullptr){
                            sibling->color = RED;
                            node = node->parent;
                        }
                }else{

                    //case 3: sibling is Black , right child is Red and left child is Black
                    if(sibling->left == nullptr || sibling->left->color == BLACK){
                        
                        if(sibling->right != nullptr){
                            sibling->right->color = BLACK;
                            sibling->color = RED;
                            leftRotate(sibling);
                            sibling = node->parent->left;
                        }
                    }

                    //case 4: sibling is Black but left child is Red
                    if(sibling != nullptr){
                        sibling->color = node->parent->color;
                        node->parent->color = BLACK;
                    }

                    if(sibling->left != nullptr){
                        sibling->left->color = BLACK;
                        rightRotate(node->parent);
                        node = root;
                    }
                }
            }
        }

        if(node != nullptr){
            node->color = BLACK;
        }
        
    }

    void delNodeInRBT(int key){
        Node* deleteNode = root;

        while(deleteNode != nullptr  && deleteNode->data != key){

            if(key < deleteNode->data){
                deleteNode = deleteNode->left;
            }else{
                deleteNode = deleteNode->right;
            }
        }

        if(deleteNode == nullptr) {
            cout << "Key not found in the tree!\n";
            return;
        }

        Node*  currentNode = deleteNode;
        Color currentNodeColor = currentNode->color;

        Node* tempNode;

        //for o child case and 1 child case
        if(deleteNode->left == nullptr){
            tempNode = deleteNode->right;
            transPlant(deleteNode, tempNode);
        }else if(deleteNode->right == nullptr){
            tempNode = deleteNode->left;
            transPlant(deleteNode, tempNode);
        }else{
            //for 2 child case
            currentNode = inorderSuccessor(deleteNode->right);
            currentNodeColor = currentNode->color;
            tempNode = currentNode->right;

            if(currentNode->parent == deleteNode){
                if(tempNode != nullptr){
                    tempNode->parent = currentNode;
                }
            }else{
                transPlant(currentNode, currentNode->right);
                currentNode->right = deleteNode->right;
                currentNode->right->parent = currentNode;
            }

            transPlant(deleteNode, currentNode);
            currentNode->left = deleteNode->left;
            currentNode->left->parent = currentNode;
            currentNode->color = deleteNode->color;
        }

        delete(deleteNode);

        if(currentNodeColor == BLACK){
            deleteFix(tempNode);
        }

    }
    
    void inorder(Node* root){

        if(root == nullptr){
            return;
        }

        inorder(root->left);
        cout<<root->data<< " (" << (root->color == RED ? "R" : "B") << ") ";
        inorder(root->right);
    }

    void display(){

        cout<<"Inorder of the RBT is: "<<endl;
        inorder(root);
        cout<<endl;
    }

    
};

int main(){

    int n;
    cout<<"Enter the number of nodes to insert:"<<endl;
    cin>>n;

    vector<int> values(n);

    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    RBTTree* rootOBJ = new RBTTree();

    for(int ele : values){
        rootOBJ->insertNode(ele);
    }

    rootOBJ->display();

    return 0;
}
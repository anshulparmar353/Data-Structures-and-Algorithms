#include<iostream>
#include<queue>
using namespace std;
                  
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//successor = left most node of the right subtree
Node* getInorderSuccessor(Node* root){

    while(root != NULL && root->left != NULL){
        root = root->left;
    }

    return root;
}

//predecessor = right most node of the left subtree
Node* getInorderPredecessor(Node* root){

    while(root != NULL && root->right != NULL){
        root = root->right;
    }

    return root;
}

Node* insert(Node* root,int key){

    if(root == NULL){
        return new Node(key);
    }

    if(root->data > key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }

    return root;
}

Node* delNode(Node* root, int key){

    if(root == NULL){
        return NULL;
    }

    if(root->data > key){
        root->left = delNode(root->left,key);
    }else if(root->data < key){
        root->right = delNode(root->right,key);
    }else{
        //key == root
        // for 0 child and 1 child case
        if(root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }else{ //for 2 child case
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root;
}

Node* search(Node* root, int key){

    if(root == NULL || root->data == key){
        return root;
    }

    if(root->data > key){
        search(root->left,key);
    }else{
        search(root->right,key);
    }

}

Node* BuildBST(vector<int>&arr){

    Node* root = NULL;

    for(int val : arr){
        root = insert(root,val);
    }

    return root;
}


void inorder(Node* root){

    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){

    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root){

    queue<Node*> qu;

    qu.push(root);
    qu.push(NULL);

    while(qu.size() > 0){

        Node* curr = qu.front();
        qu.pop();

        if(curr==NULL){
            if(!qu.empty()){
                cout<<endl;
                qu.push(NULL);
                continue;
            }else{
                break;
            }
        }

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            qu.push(curr->left);
        }

        if(curr->right != NULL){
            qu.push(curr->right);
        }
    }

}

int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right) + 1;
}

int countNodes(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftcount = countNodes(root->left);
    int rightcount = countNodes(root->right);

    return (leftcount + rightcount + 1);
}

int sumofNodes(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftsum = sumofNodes(root->left);
    int rightsum = sumofNodes(root->right);

    return (leftsum + rightsum + root->data);
}



int main(){

    // Node* root = new Node(1);

    // root->left = new Node(2);
    // root->right = new Node(3);

    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    
    // cout<<"Root: "<<root->data<<endl;
    // cout<<"Left child of Root: "<<root->left->data<<endl;
    // cout<<"Right child of Root: "<<root->right->data<<endl;

    // inorder(root);
    // cout<<endl;

    // preorder(root);
    // cout<<endl;

    // postorder(root);
    // cout<<endl;

    // levelorder(root);
    // cout<<endl;


    vector<int> arr = {50,30,20,40,70,60,80};

    Node* root = BuildBST(arr);
    cout<<"Before: ";
    inorder(root);
    cout<<endl;

    // delNode(root,6);
    // cout<<"After: ";  
    // inorder(root);
    // cout<<endl;

    // cout<<isBalanced(root);

    cout<<"sum: "<<sumofNodes(root)<<endl;

    cout<<"count: "<<countNodes(root)<<endl;

    return 0;
}
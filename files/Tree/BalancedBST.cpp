#include<iostream>
#include<vector>
using namespace std;

class Tree{
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val){
        data = val;
        left = right = nullptr;
    }
};

Tree* helptoBalanced(vector<int>&arr, int srt, int end){

    if(srt > end){
        return NULL;
    }

    int mid = srt + (end-srt)/2;

    Tree* root = new Tree(arr[mid]);

    root->left = helptoBalanced(arr,srt,mid-1);
    root->right = helptoBalanced(arr,mid+1,end);

    return root;
}

Tree* balancedBStFromSortedArray(vector<int> &arr){

    int srt = 0;
    int end = arr.size() - 1;

    return helptoBalanced(arr,srt,end);
}

void inorder(Tree* root){
    
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){

    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;

    vector<int> arr(n,-1);

    cout<<"Enter the sorted array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Tree* root = balancedBStFromSortedArray(arr);

    inorder(root);
    
    return 0;
}
#include<iostream>
using namespace std;
                  
class BinaryTree{
public:
    int* arr;
    int size;

    BinaryTree(int n){
        size = n;
        arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = -1;
        }
    }

    void setRoot(int key){
        arr[0] = key;
    }

    void setLeft(int parent , int key){
        int left = 2*parent + 1;
        if(left < size){
            arr[left] = key;
        }
    }

    void setRight(int parent , int key){
        int right = 2*parent + 2;
        if(right < size){
            arr[right] = key;
        }
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<"index "<<i<<": "<<arr[i]<<endl;
        }
    }
};


int main(){

    BinaryTree BT1(10);

    BT1.setRoot(6);
    BT1.setLeft(0,4);
    BT1.setRight(0,9);
    BT1.setLeft(1,2);
    BT1.setRight(1,5);
    BT1.setRight(2,7);
    BT1.display();
    
    return 0;
}
#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};


class DoublyLinklist{
public:

    Node* head;
    Node* tail;

    DoublyLinklist(){
        head = NULL;
        tail = NULL;
    }

  
    void insertAtTail(int val){

        Node* new_node = new Node (val);

        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }

    void display (){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

Node* reverseTheLinklist(Node* &head,Node* &tail){

    Node* currptr = head;

    while (currptr!=NULL){
        Node* nextptr = currptr->next;
        currptr->next = currptr->prev;
        currptr->prev = nextptr;
        currptr = nextptr;
    }

    //swapping the head and tail pointer
    Node* newhead = tail;
    tail = head;
    head = newhead;
}


int main(){

   
    DoublyLinklist dl1;
    dl1.insertAtTail(1);
    dl1.insertAtTail(2);
    dl1.insertAtTail(3);
    dl1.insertAtTail(4);
    dl1.insertAtTail(5);
    dl1.insertAtTail(6);
    dl1.display();

    reverseTheLinklist(dl1.head,dl1.tail);
    dl1.display();

  
    return 0;
}
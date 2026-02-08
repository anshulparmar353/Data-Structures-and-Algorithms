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

    void insertAtHead(int val){

        Node* new_Node = new Node (val);
    
        if(head==NULL){
            head = new_Node;
            tail = new_Node;
            return;
        }
    
        new_Node->next = head;
        head->prev = new_Node;
        head = new_Node;
        return;
    }

    void insertAtTail(int val){

        Node* new_node = new Node (val);

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }

    void insertAtArbitary(int val, int k){

        Node* new_node = new Node (val);

        Node* temp = head;
        int count = 0;
        while(count<k){
            temp = temp->next;
            count++;
        }

        new_node->next = temp;
        temp->prev->next = new_node;
        temp->prev = new_node;
        new_node->prev = temp->prev;
        
        return;

    }

    void deleteAtHead(){

        Node* temp = head;
        temp->prev = NULL;
        head = temp->next;
        free(temp);

    }

    void deleteAtTail(){
        
        Node* temp = tail;
        temp->prev->next = NULL;
        tail = temp->prev;
        free(temp);
    }

    void deleteAtArbitary(int k){

        Node* temp = head;
        int count = 0;
        while (count<k){
            temp = temp->next;
            count++;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
        
    }

    void display (){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};


int main(){

    // Node* newNode = new Node(4);

    // DoublyLinklist dl1;
    // dl1.head = newNode;
    // dl1.head = newNode;
    // display(dl1.head);
    DoublyLinklist dl1;
    dl1.insertAtHead(3);
    dl1.insertAtHead(2);
    dl1.insertAtHead(1);
    dl1.insertAtTail(4);
    dl1.display();

    // dl1.insertAtArbitary(5,2);
    // dl1.display();

    // dl1.deleteAtHead();
    // dl1.display();
    
    // dl1.deleteAtTail();
    // dl1.display();

    dl1.deleteAtArbitary(2);
    dl1.display();
    
    return 0;
}
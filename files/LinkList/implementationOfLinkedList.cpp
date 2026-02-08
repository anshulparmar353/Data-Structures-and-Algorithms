#include<iostream>
using namespace std;    

class Node{
public:

    int val;
    Node* next;

    Node (int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head , int val){

    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtTail(Node* &head , int val){

    Node* new_node = new Node(val);

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new_node;
    //automatically last node point to NULL because of class Node (next = NULL)
    //new_node->next = NULL;
}

void insertAtArbitary(Node* &head, int pos ,int val){

    Node* new_node = new Node(val);

    if(pos==0){
        insertAtHead(head,val);
        return;
    }

    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=pos-1){
        temp = temp->next;
        current_pos++;
    }

    //temp is pointing node at pos-1
    new_node->next = temp->next;
    temp->next = new_node;
    
}

void updationAtPostition(Node* &head, int k ,int val){

    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=k){
        temp = temp->next;
        current_pos++;
    }

    // temp is pointing at kth node
    temp->val = val;
}

void deletionAtHead(Node* &head){

    Node* temp = head;
    head = temp->next;
    free(temp);

}

void deletionAtTail(Node* &head){

    Node* second_last = head;
    while(second_last->next->next!=NULL){
        second_last = second_last->next;
    }

    //now secondlast node point  to second last node
    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);
}

void deletionAtArbitary(Node* &head , int pos){

    if(pos==0){
        deletionAtHead(head);
        return;
    }

    Node* prev = head;
    int current_pos = 0;
    while(current_pos!=pos-1){
        prev = prev->next;
        current_pos++;
    }

    //temp in pointing at pos-1
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);

}

void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){

    // Node* n = new Node(1);
    // cout<<n->val<<"->"<<n->next<<"->NULL";

    Node* head = NULL;
    insertAtHead(head,2);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertAtArbitary(head,2,5);
    display(head);
    // updationAtPostition(head,1,14);
    // display(head);
    // deletionAtHead(head);
    // display(head);
    // deletionAtTail(head);
    // display(head);
    deletionAtArbitary(head,1);
    display(head);
    return 0;
}
#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class Linklist{
public:
    Node* head;

    Linklist(){
        head = NULL;
    }

    void insertTail(int val){

        Node* new_node = new Node(val);
        if(head==NULL){
            head = new_node;
            return;
        }

        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void display(){

        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};

Node* reverseLinks(Node* &head){

    Node* prevptr = NULL;
    Node* currentptr = head;
   
    //linking in reverse order
    while(currentptr!=NULL){
        Node* nextptr = currentptr->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr;
    }

    //prev is at last node which is a new head
    Node* new_head = prevptr;

    return new_head;
}

int main(){

    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(4);
    l1.insertTail(5);
    l1.insertTail(6);
    l1.display();
    l1.head =reverseLinks(l1.head);
    l1.display();
    
    return 0;
}
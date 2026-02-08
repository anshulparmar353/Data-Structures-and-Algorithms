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

Node* reverseLinksAtKth(Node* &head,int k){

    Node* prev = NULL;
    Node* curr = head;

    int counter = 0;
    while(curr!=NULL && counter<k){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        counter++;
    }

    if(curr!=NULL){
        Node* new_head = reverseLinksAtKth(curr,k);
        head->next = new_head;
    }

    return prev;

}

int main(){
    
    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(4);
    l1.insertTail(5);
    l1.insertTail(6);
    cout<<"THE GIVEN LINKLIST IS: "<<endl;
    l1.display();
    cout<<endl;
    cout<<"THE REVERSE LINKLIST IS:  "<<endl;
    l1.head = reverseLinksAtKth(l1.head,2);
    l1.display();
    
    return 0;
}
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

Node* arrange(Node* &head){
    Node* evenhead = head->next;
    Node* oddptr = head;
    Node* evenptr = evenhead;

    while(evenptr!=NULL && evenptr->next!=NULL){
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }

    oddptr->next = evenhead;
    return head;
}


int main(){

    cout<<"THE GIVEN LINKLIST IS: "<<endl;
    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(4);
    l1.insertTail(5);
    l1.insertTail(6);
    l1.display();
    cout<<endl;
    cout<<"THE ARRANGE LINKLIST IS:  "<<endl;
    l1.head = arrange(l1.head);
    l1.display();
    // Linklist newlist;
    // newlist.head = arrange(l1.head);
    // newlist.display();

    return 0;
}
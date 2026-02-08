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

Node* reorderList(Node* &head){

    //finding the mid element
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //slow is pointing at the mid element
    //reverse link of the second half
    Node* curr = slow->next;
    slow->next = NULL;
    Node* prev = slow;
    while(curr!=NULL){
        Node* nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }

    //merging the twp half of the linklist
    Node* ptr1 = head;
    Node* ptr2 = prev;

    while(ptr1!=ptr2){
        Node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }

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
    l1.insertTail(7);
    l1.display();
    
    l1.head = reorderList(l1.head);
    l1.display();

    return 0;
}
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

int getlength(Node* &head){
    Node* temp = head;
    int length = 0;

    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

Node* moveAhead(Node* &head, int k){
    Node* ptr = head;
    while(k--){
        ptr = ptr->next;
    }
    return ptr;
}

Node* intersectOrNot(Node* &head1 ,Node* &head2){
    
    //fing length of both the linklist
    int l1 = getlength(head1);
    int l2 = getlength(head2);

    //fing difference bw the linklist k
    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        int k = l1-l2;
        ptr1 = moveAhead(head1,k);
        ptr2 = head2;
    }else{
        int k = l2-l1;
        ptr1 = head1;
        ptr2 = moveAhead(head2,k);
    }

    //compare ptr1 and ptr2 nodes
    while(ptr1!=NULL){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main(){

    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(4);
    l1.insertTail(5);
    l1.display();

    Linklist l2;
    l2.insertTail(6);
    l2.insertTail(7);
    l2.head->next->next = l1.head->next->next->next;
    l2.display();
         
    Node* intersection = intersectOrNot(l1.head,l2.head);
    if(intersection){
        cout<<intersection->val<<endl;
    }else{
        cout<<"-1"<<endl;
    }

    return 0;
}
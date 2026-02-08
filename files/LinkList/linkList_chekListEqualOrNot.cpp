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

bool checkListEqualOrNot(Node* head1,Node* &head2){

    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val != ptr2->val){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    //at the end either ptr1 is NULL or ptr2 is NULL or both is NULL
    return (ptr1==NULL && ptr2==NULL);
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

    Linklist l2;
    l2.insertTail(1);
    l2.insertTail(2);
    l2.insertTail(3);
    l2.insertTail(4);
    l2.insertTail(5);
    l2.insertTail(6);
    l2.display();

    cout<<"BOTH LINKLIST ARE: "<<checkListEqualOrNot(l1.head,l2.head)<<endl;

    
    return 0;
}
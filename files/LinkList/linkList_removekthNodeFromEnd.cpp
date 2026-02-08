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

//k shoukd be lees or equal than lenth of the linkList
void removekthNodeFromEnd(Node* &head,int k){

    Node* ptr1 = head;
    Node* ptr2 = head;
    
    //move ptr2 k steps ahead
    int count = k;
    while(count--){
        ptr2 = ptr2->next;
    }

    //if k is equal to the length
    if(ptr2==NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    //now ptr2 is ahead of ptr1
    while (ptr2->next!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    //now ptr1 is pointing at the kth node from end 
    //node will be deleted is ptr1->next
    
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);

}

int main(){

    Linklist l1;
    l1.insertTail(1);
    l1.insertTail(2);
    l1.insertTail(3);
    l1.insertTail(4);
    l1.insertTail(5);
    l1.insertTail(6);

    removekthNodeFromEnd(l1.head,3);
    l1.display();


    

    return 0;
}
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

Node* rotateBykNodes(Node* &head,int k){

    //1.find n = lenght of linkllst
    int n = 0;
    //2.find tail Node
    Node* tail = head;
    while(tail->next!=NULL){
        n++;
        tail = tail->next;
    }
    n++;

    k=k%n;
    if(k==0){
        return head;
    }

    tail->next = head;
    //3.traverse n-k nodes
    Node* temp = head;
    for(int i=1; i<n-k; i++){
        temp = temp->next;
    }

    //temp is pointinf n-kth node

    Node* new_head = temp->next;
    temp->next = NULL;

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

    l1.head = rotateBykNodes(l1.head,3);
    l1.display();


    return 0;
}
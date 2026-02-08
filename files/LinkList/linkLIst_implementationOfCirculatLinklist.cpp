#include<iostream>
#include<vector>
#include<climits>
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


class CircularLinklist{
public:

    Node* head;

    CircularLinklist(){
        head = NULL;
    }

    void display (){

        Node* temp = head;

        do{
            cout<<temp->val<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<endl;
    }

    void insertAthead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        //now tail is pointing the last Node
        newNode->next = head;  
        tail->next = newNode;
        head = newNode;

    }

    void insertAtTail(int val){
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

        Node* newNode = new Node (val);
        tail->next = newNode;
        newNode->next = head;

    }


    void insertAtArbitary(int val,int k){
        Node* newNode = new Node(val);

        Node* temp = head;
        int count = 0;
        while(count<k-1){
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        

        return;
    }

    void printcircular(int n){

        Node* temp = head;
        for(int i=0; i<n; i++){
            cout<<temp->val<<"->";
            temp = temp->next;
        }

        return;
    }

    void deleteAtHead(){

        if(head==NULL){
            return;
        }

        Node* temp = head;
        Node* tail = head;
        while(tail->next!=head){
            tail = tail->next;
        }

      
        tail->next = head->next;
        head = temp->next;
        free(temp);

    }

    void deleteAtTail(){

        Node* temp = head;
        while(temp->next->next!=head){
            temp = temp->next;
        }

        Node* deleteEle = temp->next;
        temp->next = head;
        free(deleteEle);
    }

    void deleteAtArbitary(int k){

       Node* temp = head;
       int count = 0;
       while(count<(k-1)){
        temp = temp->next;
        count++;
       }

       Node* deleteEle = temp->next;
       temp->next = deleteEle->next;
       free(deleteEle);
    }
    
};



int main(){

    CircularLinklist cl1;
    
    cl1.insertAthead(3);
    cl1.insertAthead(2);
    cl1.insertAthead(1);    
    cl1.insertAtTail(4);
    cl1.insertAtTail(5);
    cl1.insertAtTail(6);
    cl1.display();

    // cl1.insertAtArbitary(11,3);
    // cl1.display();

    // cl1.printcircular(20);

    // cl1.deleteAtHead();
    // cl1.display();

    // cl1.deleteAtTail();
    // cl1.display();
    
    cl1.deleteAtArbitary(3);
    cl1.display();

    return 0;
}

#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
        prev = NULL;
    }
};


class DoublyLinklist{
public:

    Node* head;
    Node* tail;

    DoublyLinklist(){
        head = NULL;
        tail = NULL;
    }

  
    void insertAtTail(int val){

        Node* new_node = new Node (val);

        if(head==NULL){
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }

    void display (){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }
};

bool checkPalindromeOrNot(Node* head , Node* tail){
  
    while(head!=tail && tail != head->prev){
        
        if(head->val!=tail->val){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
}


int main(){

   
    DoublyLinklist dl1;
    dl1.insertAtTail(1);
    dl1.insertAtTail(2);
    dl1.insertAtTail(3);
    dl1.insertAtTail(2);
    dl1.insertAtTail(1);
    dl1.display();

    cout<<checkPalindromeOrNot(dl1.head,dl1.tail)<<endl;

  
    return 0;
}
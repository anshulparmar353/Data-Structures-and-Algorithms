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

Node* neighborsCheck(Node* &head, Node* &tail){

    Node* currNode = tail->prev;
    while(currNode!=head){
        Node* prevNode = currNode->prev;
        Node* nextNode = currNode->next;
        if(nextNode->val==prevNode->val){
            //now we have to delete the currNode
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            free(currNode);
        }
        currNode = prevNode;

    }
}

int main(){

   
    DoublyLinklist dl1;
   
    dl1.insertAtTail(2);
    dl1.insertAtTail(1);
    dl1.insertAtTail(1);
    dl1.insertAtTail(2);
    dl1.insertAtTail(1);
    dl1.display();

    dl1.head = neighborsCheck(dl1.head,dl1.tail);
    dl1.display();
  
    return 0;
}
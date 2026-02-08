#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL; 
    }
};

class Queue{
    Node* head;
    Node* tail;
    int size;
public:
    Queue(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int data){
        Node* newNode = new Node(data);
        if(this->head==NULL){
            this->head = newNode;
            this->tail = newNode;
            return;
        }else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue(){
        if(this->head == NULL){ 
            return;
        }else{
            Node* oldhead = this->head;
            Node* newhead = this->head->next;
            this->head = newhead;
            if(this->head==NULL) this->tail=NULL;
            oldhead->next = NULL;
            delete oldhead;
            this->size--;
        } 
    }


    int getSize(){
        return this->size;
    }

    int getFront(){
        if(this->head == NULL) return -1;
        return this->head->data;
    }
     
    bool isEmpty(){
        return this->head == NULL;
    }

    bool isFull(){
        return this->head == this->tail;
    }


};

int main(){

    Queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);

    while(!q1.isEmpty()){
        cout<<q1.getFront()<<" ";
        q1.dequeue();
    }cout<<endl;
 
   
    return 0;
}
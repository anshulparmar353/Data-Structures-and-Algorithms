#include<iostream>
#include<climits>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Stack {
public:

    Node* head;
    int capacity;
    int currsize;
    Stack (int c){
        this->capacity = c;
        this->currsize = 0;
        head = NULL;
    }

    bool isEmpty(){
        return this->head == NULL;
    }

    bool isFull(){
        return this->currsize == capacity;
    }

    void push(int data){
    
        if(this->currsize == this->capacity){
            cout<<"Overflow";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->currsize++;
    }

    int pop(){
        
        if(this->head == NULL){
            cout<<"Underflow";
            return INT_MIN;
        }

        Node* newhead = this->head->next;
        this->head->next = NULL;
        Node* tobeRemoved = this->head;
        int result = tobeRemoved->data;
        delete tobeRemoved;
        this->head = newhead;
        return result;
    }


    int getTop(){

        if(head==NULL){
            cout<<"Underflow";
            return INT_MIN;
        }

        return this->head->data;

    }

    int size(){
        return this->currsize;
    }


};

int main(){

    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<endl;
    st.push(8);
 
    st.pop();
    st.pop();
    cout<<endl;

    cout<<st.getTop()<<endl;

    return 0;

}
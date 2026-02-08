#include<iostream>
#include<vector>
using namespace std;

class CircularQueue{
    
    vector<int> v;
    int front;
    int back;
    int cs; // current size
    int ts; // total size

public:
    CircularQueue(int n){
        v.resize(n);
        front = 0;
        back =  n-1;
        cs = 0;
        ts = n;
    }

    void enqueue(int data){
        if(isFull()) return;
        this->back = (this->back + 1) % this->ts;
        this->v[this->back] = data;
        this->cs++;
    }

    void dequeue(){
        if(isEmpty()) return;
        this->front = (this->front + 1) % this->ts;
        this->cs--;
    }

    int getFront(){
        if(this->cs == 0) return -1;
        return v[this->front];
    }

    bool isFull(){
        return this->cs == this->ts;
    }

    bool isEmpty(){
        return this->cs == 0;
    }
};
                    
int main(){

    CircularQueue cq(4);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(50);

    while(!cq.isEmpty()){
        cout<<cq.getFront()<<" ";
        cq.dequeue();
    }cout<<endl;

    return 0;
}
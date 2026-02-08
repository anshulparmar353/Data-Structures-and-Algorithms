#include<iostream>
#include<vector>
using namespace std;

class Queues{
    vector<int> v;
    int front;
    int back;
public:
    Queues(){
        this->front = -1;
        this->back = -1;
    }

    void enqueue(int data){
        if(this->back == 0) this->front = 0;
        this->v.push_back(data);
        this->back++;
    }

    void dequeue(){
        if(this->front == this->back ){
            this->front = this->back = -1;
            this->v.clear();
        }else{
            this->front++;
            }
    }

    int getFront(){
        if(this->front == -1) return -1;
        return this->v[this->front];
    }

    bool isEmpty(){
        return this->front == -1;
    }

};

int main(){

    Queues q1;
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.dequeue();
    q1.dequeue();

    while(!q1.isEmpty()){
        cout<<q1.getFront()<<" ";
        q1.dequeue();
    }cout<<endl;

    
    return 0;
}
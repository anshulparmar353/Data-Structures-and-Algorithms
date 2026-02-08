#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> q1;
    q1.push(5); //enqueue
    q1.push(6);
    q1.push(7);
    q1.push(8);
    q1.push(9);
    q1.pop(); //dequeue

    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }cout<<endl;
    
    return 0;
}
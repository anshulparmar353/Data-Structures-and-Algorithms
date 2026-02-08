#include<iostream>
#include<stack>
#include<climits>
using namespace std;
                    
class Queue{
    stack<int> st;
public:
    Queue() {}

    void push(int x){

        if(this->st.empty()){
            this->st.push(x);
            return;
        }

        stack<int> temp;
        while(!this->st.empty()){
            temp.push(this->st.top());
            this->st.pop();
        }
        this->st.push(x);

        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
    }

    void pop(){

        if(this->st.empty()) return;
        this->st.pop();
    }

    bool isEmpty(){
        return this->st.empty();
    }

    int front(){
        if(this->st.empty()) return INT_MAX;
        return this->st.top();
    }

};

int main(){

    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.pop();
    qu.pop();

    while(!qu.isEmpty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }cout<<endl; 
    
    return 0;
}
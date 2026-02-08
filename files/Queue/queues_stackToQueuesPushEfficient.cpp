#include<iostream>
#include<stack>
using namespace std;

class Queue{
   stack<int> st;
public:

    Queue() {}

    void push(int x){
        this->st.push(x);
    }

    void pop(){

        if(this->st.empty()) return;
        
        stack<int> temp;
        while(this->st.size() > 1){
            temp.push(st.top());
            this->st.pop();
        }
        this->st.pop();

        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }
    }

    bool isEmpty(){
        return this->st.empty();
    }

    int getFront(){

        if(this->st.empty()) return -1;

        stack<int> temp;
        while(st.size() > 1){
            temp.push(this->st.top());
            this->st.pop();
        }
        int result = this->st.top();

        while(!temp.empty()){
            this->st.push(temp.top());
            temp.pop();
        }

        return result;
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
        cout<<qu.getFront()<<" ";
        qu.pop();
    }cout<<endl;


    
    return 0;
}
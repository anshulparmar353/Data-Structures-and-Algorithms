#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class Stack{
    queue<int> qu;
public:
    Stack() {}

    void push(int x){

        if(this->qu.empty()){
            this->qu.push(x);
            return;
        }

        queue<int> temp;
        while(!this->qu.empty()){
            temp.push(this->qu.front());
            this->qu.pop();
        } 
        this->qu.push(x);

        while(!temp.empty()){
            this->qu.push(temp.front());
            temp.pop();
        }

    }

    void pop(){
        if(this->qu.empty()) return;
        this->qu.pop();
    }

    bool isEmpty(){
        return this->qu.empty();
    }

    int getTop(){

        if(this->qu.empty()) return INT_MAX;
        return this->qu.front();
    }
};
                    
int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();

    while(!st.isEmpty()){
        cout<<st.getTop()<<" ";
        st.pop();
    }cout<<endl;
     

    
    return 0;
}
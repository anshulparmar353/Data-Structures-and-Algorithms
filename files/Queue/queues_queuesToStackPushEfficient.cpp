#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> qu;
public:
    Stack(){}

    void push(int x){
        this->qu.push(x);
    }

    void pop(){

        if(this->qu.empty()) return;

        queue<int> temp;
        while(this->qu.size() > 1){
            temp.push(this->qu.front());
            this->qu.pop();
        }
        this->qu.pop();

        while(!temp.empty()){
            this->qu.push(temp.front());
            temp.pop();
        }
    }

    bool isEmpty(){
        return this->qu.empty();
    }

    int getTop(){

        if(this->qu.empty()) return -1;
        
        queue<int> temp;
        while(this->qu.size() > 1){
            temp.push(this->qu.front());
            this->qu.pop();
        }
        int result = this->qu.front();

        while(!temp.empty()){
            this->qu.push(temp.front());
            temp.pop();
        }
        return result;
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

   
    cout<<st.getTop()<<" ";
     


    
    return 0;
}
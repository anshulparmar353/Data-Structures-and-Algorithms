#include<iostream>
#include<stack>
using namespace std;

void deleteAtArbitary(stack<int> &st, int k){

    stack<int> temp;
    while(st.size() - 1 > k){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();

    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }

}

void f(stack<int> &st,int k){

    if(st.size()-1 == k){
        st.pop();
        return;
    }

    int curr = st.top();
    st.pop();
    f(st,k);
    st.push(curr);
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"ENTER THE DELETING ARBITARY POSITION"<<endl;
    int k;
    cin>>k;

    // deleteAtArbitary(st,3);

    f(st,k);
    cout<<"THE UPDATED STACK IS: "<<endl;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }


    
    return 0;
}
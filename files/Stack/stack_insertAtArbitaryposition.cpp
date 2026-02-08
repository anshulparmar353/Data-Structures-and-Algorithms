#include<iostream>
#include<stack>
using namespace std;

void insertAtArbitary(stack<int> &st, int x, int k){

    stack<int> temp;
    int count = 0;
    int n = st.size();
    while(count< n-k){
        count++;
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);

    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void f(stack<int> &st, int x, int k){

    if(st.size()==k){
        st.push(x);
        return;
    }

    int curr = st.top();
    st.pop();
    f(st,x,k);
    st.push(curr);

}

int main(){
    
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"INSERTING VALUE"<<endl;

    int x;
    cin>>x;

    cout<<"INSERTING POSITION"<<endl;
    int k;
    cin>>k;

    // insertAtArbitary(st,x,k);

    // cout<<"THE UPDATED STACK IS: "<<endl;

    // while(!st.empty()){
    //     int curr = st.top();
    //     st.pop();
    //     cout<<curr<<endl;
    // }

    //RECURSIVELY
    cout<<"THE UPDATED STACK IS: "<<endl;
    f(st,x,k);

    while(!st.empty()){
        int curr = st.top();
        st.pop();
        cout<<curr<<endl;
    }
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.top()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.top()<<endl;
    st.push(8);
 
    st.pop();
    st.pop();
    cout<<endl;

    cout<<st.top()<<endl;
    
    return 0;
}